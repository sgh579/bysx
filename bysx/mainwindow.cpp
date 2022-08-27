#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_standardOutput(stdout)
{
    ui->setupUi(this);
    m_standardOutput<<"hello bysx,here is mainwindow()"<<endl;
    connect(ui->debugButton,&QPushButton::clicked,this,&MainWindow::debugButtonCallback);

    serialPort.close();//先关上
    serialPort.setPortName("COM3");
    serialPort.setParity(QSerialPort::EvenParity);
    int serialPortBaudRate = 9600;
    serialPort.setBaudRate(serialPortBaudRate);
    if(!serialPort.open(QIODevice::ReadWrite))
    {
        qDebug()<<tr("can't open %1 ,error code %2")
                  .arg(serialPort.portName()).arg(serialPort.error())<<endl;
        return;
    }
    else
        qDebug()<<tr(" open %1 successfully")
                  .arg(serialPort.portName())<<endl;


    serialPortWriter = new writer(&serialPort);
    m_standardOutput<<"writer object built successfully"<<endl;
    serialPortWriter->write();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::debugButtonCallback()
{

    serialPortWriter->write();

}
