#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QDialog>
#include <QColor>
#include <QColorDialog>

namespace Ui {
class MessageDialog;
}

class MessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MessageDialog(QWidget *parent = nullptr);
    ~MessageDialog();

    QString getName() const;
    QString getMessage() const;
    QColor getColor() const;

signals:
    void accepted(const QString &name, const QString &message, const QColor &color);

private slots:
    void on_colorButton_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::MessageDialog *ui;
    QColor m_color;
};

#endif // MESSAGEDIALOG_H
