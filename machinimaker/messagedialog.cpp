#include "messagedialog.h"
#include "ui_MessageDialog.h"
#include "messagequeue.h"

MessageDialog::MessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);

    // Connect the 'OK' button to the custom slot
    //connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &MessageDialog::on_buttonBox_accepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &::MessageDialog::on_buttonBox_accepted);

    //default color
    m_color = QColor(36, 120, 253);
}

MessageDialog::~MessageDialog()
{
    delete ui;
}

QString MessageDialog::getName() const
{
    return ui->nameLineEdit->text();
}

QString MessageDialog::getMessage() const
{
    return ui->messageTextEdit->toPlainText();
}

QColor MessageDialog::getColor() const
{
    return m_color;
}

void MessageDialog::on_colorButton_clicked()
{
    // Open the standard color dialog and update the color member
    m_color = QColorDialog::getColor(m_color, this, "Choose a Color");

    if (m_color.isValid()) {
        // Update the color frame to show the selected color
        QString styleSheet = QString("background-color: %1").arg(m_color.name());
        ui->colorFrame->setStyleSheet(styleSheet);
    }
}

void MessageDialog::on_buttonBox_accepted()
{
    Message msg;
    msg.name = ui->nameLineEdit->text();
    msg.text = ui->messageTextEdit->toPlainText();
    msg.color = m_color;

    MessageQueue::instance()->addMessage(msg);

    QDialog::accept();
}

void MessageDialog::on_buttonBox_rejected(){
    QDialog::reject();
}

