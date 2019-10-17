#include "dialog.h"
#include "ui_dialog.h"
#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QDoubleValidator>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QIntValidator* intValidator =
           new QIntValidator(ui->intLineEdit);
    ui->intLineEdit->setValidator(intValidator);

    QIntValidator* byteIntValidator =
           new QIntValidator(0, 255, ui->int255lineEdit);
    ui->int255lineEdit->setValidator(byteIntValidator);

    //byteIntValidator->validate(ui->int255lineEdit->text().toInt(), );

    QRegularExpressionValidator* binaryValidator =
           new QRegularExpressionValidator(QRegularExpression("[01]{1,8}"), ui->binaryLineEdit);
    ui->binaryLineEdit->setValidator(binaryValidator);

    QRegularExpressionValidator* hexValidator =
           new QRegularExpressionValidator(QRegularExpression("[0-9A-Fa-f]{1,2}"));
    ui->hexLineEdit->setValidator(hexValidator);

    QDoubleValidator* floatValidator =
            new QDoubleValidator(-100.00, 100.00, 1, ui->floatLineEdit);
    ui->floatLineEdit->setValidator(floatValidator);

    QRegExpValidator* lowerValidator =
            new QRegExpValidator(QRegExp("[a-z]{1,15}"), ui->lCaseLineEdit );
    ui->lCaseLineEdit->setValidator(lowerValidator);

    QRegExpValidator* allCaseValidator =
            new QRegExpValidator(QRegExp("[a-zA-Z]{1,15}"), ui->allCaseLineEdit);
    ui->allCaseLineEdit->setValidator(allCaseValidator);

    QRegExp phoneRegEx("[0-9]{3}-[0-9]{3}-[0-9]{4}");
    QRegExpValidator* phoneRegExpValidator =
            new QRegExpValidator(phoneRegEx, ui->phoneLineEdit);
    ui->phoneLineEdit->setValidator(phoneRegExpValidator);


}

Dialog::~Dialog()
{
    delete ui;
}
