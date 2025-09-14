#include "machinimaker.h"
#include "./ui_machinimaker.h"

machinimaker::machinimaker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::machinimaker)
{
    ui->setupUi(this);
}

machinimaker::~machinimaker()
{
    delete ui;
}
