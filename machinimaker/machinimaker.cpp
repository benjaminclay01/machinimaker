#include "machinimaker.h"
#include "./ui_machinimaker.h"

#include <QApplication>
#include <QStyle>
#include <QLayout>


machinimaker::machinimaker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::machinimaker)
{
    ui->setupUi(this);

    ui->toolBar->setStyleSheet("background: #ebedfa; border-bottom: 2px groove #6c6c6c");
    ui->Viewport->setStyleSheet("background-color: #00FF00;");
    ui->DialogBox->setStyleSheet("background-color: rgb(240, 240, 240);");
    ui->Debugger->setStyleSheet("color: rgb(0, 0, 0); background-color: rgb(240, 240, 240);");
    qApp->setStyleSheet("QDockWidget::title{background: #c8c8c8; color: #000000} QTextEdit{border:1px groove #848484} QMainWindow::separator { width: 1px; height: 0px; }");


}
machinimaker::~machinimaker()
{
    delete ui;
}


