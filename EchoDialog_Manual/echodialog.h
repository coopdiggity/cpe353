#ifndef ECHODIALOG_H
#define ECHODIALOG_H

#include<QDialog>

class QLabel;
class QLineEdit;
const int MAXIMUM_LENGTH = 30;

class EchoDialog: public QDialog
{
    Q_OBJECT

public:
    EchoDialog();

private:
    QLineEdit* userInputLineEditPtr;
    QLineEdit* echoLineEditPtr;
    QLabel*    echoLabelPtr;

    QPushButton* quitButtonPtr;
    QPushButton* clearButtonPtr;
};




#endif // ECHODIALOG_H
