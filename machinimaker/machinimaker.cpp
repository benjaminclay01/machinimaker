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

    //Set up style sheets
    ui->toolBar->setStyleSheet("background: #ebedfa; border-bottom: 2px groove #6c6c6c");
    ui->Viewport->setStyleSheet("background-color: #00FF00;");
    ui->DialogBox->setStyleSheet("background-color: rgb(240, 240, 240);");
    ui->Debugger->setStyleSheet("color: rgb(0, 0, 0); background-color: rgb(240, 240, 240);");
    qApp->setStyleSheet("QDockWidget::title{background: #c8c8c8; color: #000000} QTextEdit{border:1px groove #848484} QMainWindow::separator { width: 1px; height: 0px; }");

    //connect line editor to text browser
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &machinimaker::on_Text_Entered);
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
