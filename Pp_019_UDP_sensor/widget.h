#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QUdpSocket* myUdpSocket;
private slots:
    void processPendingDatagram();
};

#endif // WIDGET_H
