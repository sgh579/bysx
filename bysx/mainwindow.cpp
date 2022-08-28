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


    ui_pro = new protocol();
    ui_equ = new equipment();


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

    serialPortReader = new reader(&serialPort);
    connect(serialPortReader,&reader::read_ready_decode_signal,ui_pro,&protocol::decode);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::debugButtonCallback()
{

    //serialPortWriter->write();
    QByteArray debug_read_data = QByteArray::fromHex("fefe681855600600006893064b88933933334116");
    if(ui_pro->decode(debug_read_data) == true)qDebug()<<"decode sucessfull"<<endl;
    else qDebug()<<"decode fail"<<endl;
    ui_pro->printMember();

}
