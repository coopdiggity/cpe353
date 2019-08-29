//echodialog.cpp

#include "echodialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

EchoDialog::EchoDialog()
{
    //Allocate layouts
    QVBoxLayout* mainLayoutPtr = new QVBoxLayout(this);
    QVBoxLayout* inputLayoutPtr = new QVBoxLayout;
    QGridLayout* echoLayoutPtr = new QGridLayout;
    QHBoxLayout* buttonLayoutPtr = new QHBoxLayout;

    setWindowTitle("Double Echo Dialog");

    //build main dialog layout;
    mainLayoutPtr->addLayout(inputLayoutPtr);
    mainLayoutPtr->addStretch();
    mainLayoutPtr->addLayout(echoLayoutPtr);
    mainLayoutPtr->addStretch();
    mainLayoutPtr->addLayout(buttonLayoutPtr);

    //build input layout
    QLabel* inputLabelPtr = new QLabel("Type your input below");

    userInputLineEditPtr = new QLineEdit;
    userInputLineEditPtr->setMaxLength(MAXIMUM_LENGTH);
    userInputLineEditPtr->setFrame(true);

    inputLayoutPtr->addWidget(inputLabelPtr);
    inputLayoutPtr->addWidget(userInputLineEditPtr);

    //Build echo layout
    QLabel* firstLabelPtr = new QLabel("Qlabel Echo");
    QLabel* secondLabelPtr = new QLabel("QLineEdit Echo");

    echoLabelPtr = new QLabel;
    echoLabelPtr->setFrameShape(QFrame::Box);
    echoLineEditPtr = new QLineEdit;
    echoLineEditPtr->setReadOnly(true);
    echoLineEditPtr->setMaxLength(MAXIMUM_LENGTH);
    echoLineEditPtr->setFrame(true);

    echoLayoutPtr->addWidget(firstLabelPtr, 0, 0);
    echoLayoutPtr->addWidget(echoLabelPtr, 0, 1);
    echoLayoutPtr->addWidget(secondLabelPtr, 1, 0);
    echoLayoutPtr->addWidget(echoLineEditPtr, 1 ,1);

    //Build close button layout
    clearButtonPtr = new QPushButton("Clear");
    quitButtonPtr = new QPushButton("Quit");

    quitButtonPtr->setDefault(true);
    buttonLayoutPtr->addWidget(clearButtonPtr);
    buttonLayoutPtr->addStretch();
    buttonLayoutPtr->addWidget(quitButtonPtr);

    //make Qt4-style signal/slot connections

    connect(quitButtonPtr, SIGNAL(clicked()), this, SLOT(accept()));

    connect(clearButtonPtr, SIGNAL(clicked()), userInputLineEditPtr, SLOT(clear()));

    connect(userInputLineEditPtr, SIGNAL(textChanged(QString)), echoLabelPtr, SLOT(setText(QString)));

    connect(userInputLineEditPtr, SIGNAL(textChanged(QString)), echoLineEditPtr, SLOT(setText(QString)));


}
