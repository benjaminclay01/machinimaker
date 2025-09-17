#include "machinimaker.h"
#include "./ui_machinimaker.h"

#include <QApplication>
#include <QStyle>
#include <QVBoxLayout>

machinimaker::machinimaker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::machinimaker)
{
    ui->setupUi(this);
    QVBoxLayout *pLayout = new QVBoxLayout(this);

    pLayout->setSpacing(0);
    pLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(pLayout);
}

machinimaker::~machinimaker()
{
    delete ui;
}
