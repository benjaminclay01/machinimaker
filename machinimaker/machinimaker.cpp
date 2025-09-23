#include "machinimaker.h"
#include "./ui_machinimaker.h"
#include "messagedialog.h"
#include "queuewindow.h"
#include "messagequeue.h"

#include <QApplication>
#include <QStyle>
#include <QLayout>

machinimaker::machinimaker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::machinimaker)
{

    ui->setupUi(this);

    //Set up style sheets
    ui->toolBar->setStyleSheet("background: #ebedfa; border-bottom: 2px groove #6c6c6c");
    ui->Viewport->setStyleSheet("background-color: #00FF00;");
    ui->DialogBox->setStyleSheet("background-color: rgb(240, 240, 240);");
    ui->Debugger->setStyleSheet("color: rgb(0, 0, 0); background-color: rgb(240, 240, 240);");
    qApp->setStyleSheet("QDockWidget::title{background: #c8c8c8; color: #000000} QTextEdit{border:1px groove #848484} QMainWindow::separator { width: 1px; height: 0px; }");

    //next message hotkey
    m_nextMessageShortcut = new QShortcut(QKeySequence("Ctrl+N"), this);

    //connect line editor to text browser
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &machinimaker::on_Text_Entered);
    connect(ui->actionNew, &QAction::triggered, this, &machinimaker::openMessageDialog);
    connect(ui->actionopen, &QAction::triggered, this, &machinimaker::on_actionShowQueue_Triggered);
    connect(m_nextMessageShortcut, &QShortcut::activated, this, &machinimaker::printQueuedMessage);
    connect(ui->actioncut, &QAction::triggered, this, &machinimaker::clearWindow);
}

machinimaker::~machinimaker()
{
    delete ui;
}

//Move line edit text to textbrowser
void machinimaker::on_Text_Entered(){
    QString inputText = ui->lineEdit->text();

    if (!inputText.isEmpty()) {
        inputText = "<b>You:</b> " + inputText;
        ui->textBrowser->append(inputText);

        //Clear the line edit after pressing Enter
        ui->lineEdit->clear();
    }
}

void machinimaker::on_actionShowQueue_Triggered()
{
    QueueWindow que(this);
    que.exec();
}

void machinimaker::openMessageDialog()
{
    //qDebug() << "on_actionOpenMessageDialog_triggered() slot was called.";
    MessageDialog dialog(this);
    dialog.exec();
}

void machinimaker::printQueuedMessage()
{
    Message msg;
    if(MessageQueue::instance()->popMessage(msg)){
        // Build the HTML string with the received data
        QString output;
        output += "<b><font color=\"" + msg.color.name() + "\">" + msg.name + "</font>: </b>";
        output += msg.text;

        // Append the formatted text to the text browser
        ui->textBrowser->append(output);
    }
}

void machinimaker::clearWindow(){
    ui->textBrowser->clear();
    MessageQueue::instance()->clearQueue();
}
