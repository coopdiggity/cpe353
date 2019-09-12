#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEvent>
#include <QKeyEvent>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::populateComboBox);


}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent * e)
{
    if (e && e->type() == QEvent::KeyPress)
    {
        QKeyEvent* ke = static_cast<QKeyEvent*>(e);
        if(ke->key() == Qt::Key_Escape)
        {
            qDebug() << "Escape";
        }
    }
    return  QMainWindow::event(e);
}

void MainWindow::keyPressEvent(QKeyEvent * ke)
{
    if (ke && ke->key() == Qt::Key_Escape)
    {
        int count = status->text().toInt();
        count ++;
        status->setNum(count);
    }
    QMainWindow::keyPressEvent(ke);
}

void MainWindow::populateComboBox()
{


}
