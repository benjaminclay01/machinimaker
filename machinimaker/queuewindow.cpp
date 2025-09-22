#include "queuewindow.h"
#include "ui_QueueWindow.h"
#include "messagequeue.h"
#include <QColor>
#include <vector>

// Model
QueueModel::QueueModel(QObject* parent) : QAbstractTableModel(parent) {}

int QueueModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return MessageQueue::instance()->getQueue().size();
}

int QueueModel::columnCount(const QModelIndex& parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return 3; // For Name, Message, and Color
}

QVariant QueueModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= MessageQueue::instance()->getQueue().size()) {
        return QVariant();
    }

    std::queue<Message> queueCopy = MessageQueue::instance()->getQueue();
    // Rebuild a temporary vector to access by index
    std::vector<Message> messages;
    while (!queueCopy.empty()) {
        messages.push_back(queueCopy.front());
        queueCopy.pop();
    }

    const Message& msg = messages.at(index.row());

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return msg.name;
        case 1: return msg.text;
        case 2: return msg.color.name();
        }
    }
    if (role == Qt::ForegroundRole) {
        return QColor(Qt::black); // Set the text color to black for all items
    }
    if (role == Qt::BackgroundRole && index.column() == 2) {
        return msg.color;
    }
    return QVariant();
}

QVariant QueueModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal) {
        if (role == Qt::DisplayRole) {
            switch (section) {
            case 0: return QString("Name");
            case 1: return QString("Message");
            case 2: return QString("Color");
            }
        }
        if (role == Qt::ForegroundRole) {
            return QColor(Qt::black); // Set the header text color to black
        }
    }
    return QVariant();
}

void QueueModel::updateModel() {
    beginResetModel();
    endResetModel();
}


//Window

QueueWindow::QueueWindow(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::QueueWindow),
    m_model(new QueueModel(this))
{
    ui->setupUi(this);
    ui->tableView->setModel(m_model);

    connect(MessageQueue::instance(), &MessageQueue::MessageAdded, this, [this](){
        m_model->updateModel();
    });
    connect(MessageQueue::instance(), &MessageQueue::MessagePopped, this, [this](){
        m_model->updateModel();
    });
}

QueueWindow::~QueueWindow() {
    delete ui;
}
