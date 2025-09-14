#ifndef MACHINIMAKER_H
#define MACHINIMAKER_H

#include <QMainWindow>

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

private:
    Ui::machinimaker *ui;
};
#endif // MACHINIMAKER_H
