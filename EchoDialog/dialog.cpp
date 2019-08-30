#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->clearButton, &QPushButton::clicked, ui->inputLineEdit, &QLineEdit::clear );




}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_bitButton_toggled(bool checked)
{
    if(checked)
        ui->bitButtonOut->setText("1");
    else if (!checked)
        ui->bitButtonOut->setText("0");


}
