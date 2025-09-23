#ifndef MACHINIMAKER_H
#define MACHINIMAKER_H

#include <QMainWindow>
#include "queuewindow.h"
#include <QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui {
class machinimaker;
}
QT_END_NAMESPACE

class machinimaker : public QMainWindow
{
    Q_OBJECT

public:
    machinimaker(QWidget *parent = nullptr);
    ~machinimaker();

private slots:
    void openMessageDialog();
    void printQueuedMessage();
    void on_Text_Entered();
    void on_actionShowQueue_Triggered();
    void clearWindow();
private:
    Ui::machinimaker *ui;
    QueueWindow* m_queueWindow;
    QShortcut* m_nextMessageShortcut;
};
#endif // MACHINIMAKER_H
