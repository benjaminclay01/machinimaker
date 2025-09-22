#ifndef QUEUEDIALOG_H
#define QUEUEDIALOG_H

#include <QDialog>
#include <QAbstractTableModel>

// Forward declaration of the Ui namespace
namespace Ui {
class QueueWindow;
}

// Custom model for the QTableView
class QueueModel : public QAbstractTableModel {
    Q_OBJECT
public:
    QueueModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

public slots:
    void updateModel();
};

class QueueWindow : public QDialog { // Inherit from QMainWindow
    Q_OBJECT
public:
    explicit QueueWindow(QWidget* parent = nullptr);
    ~QueueWindow();

private:
    Ui::QueueWindow* ui;
    QueueModel* m_model;
};

#endif // QUEUEWINDOW_H
