#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_standardOutput(stdout)
    , findPortTimerPeriod(1000)
{
    ui->setupUi(this);
    ui_pro = new protocol();
    ui_equ = new equipment();

    m_standardOutput<<"hello bysx,here is mainwindow()"<<endl;
    connect(ui->debugButton,&QPushButton::clicked,this,&MainWindow::debugButtonCallback);

    //定时刷新串口
    connect(&findPortTimer,&QTimer::timeout,this,&MainWindow::findPort);
    findPortTimer.start(findPortTimerPeriod);



    //连接串口
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::setPortParameter);



//    serialPort.close();//先关上
//    serialPort.setPortName("COM5");
//    serialPort.setParity(QSerialPort::EvenParity);
//    int serialPortBaudRate = 9600;
//    serialPort.setBaudRate(serialPortBaudRate);
//    if(!serialPort.open(QIODevice::ReadWrite))
//    {
//        qDebug()<<tr("can't open %1 ,error code %2")
//                  .arg(serialPort.portName()).arg(serialPort.error())<<endl;
//        return;
//    }
//    else
//        qDebug()<<tr(" open %1 successfully")
//                  .arg(serialPort.portName())<<endl;


//    serialPortWriter = new writer(&serialPort);
//    m_standardOutput<<"writer object built successfully"<<endl;
//    serialPortWriter->write();

//    serialPortReader = new reader(&serialPort);
//    connect(serialPortReader,&reader::read_ready_decode_signal,ui_pro,&protocol::decode);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::debugButtonCallback()
{

    //serialPortWriter->write();
//    QByteArray debug_read_data = QByteArray::fromHex("fefe681855600600006893064b88933933334116");
//    if(ui_pro->decode(debug_read_data) == true)qDebug()<<"decode sucessfull"<<endl;
//    else qDebug()<<"decode fail"<<endl;

    serialPortReader->emit_debug_signal();
    ui_pro->printMember();

}

void MainWindow::findPort()
{
    QString temp=ui->serialPort_comboBox->currentText();
    int currentIndex=0;
    int intNum=0;
    intNum = ui->serialPort_comboBox->count();
    for(;intNum>0;intNum--)ui->serialPort_comboBox->removeItem(intNum-1);
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
    {
        ui->serialPort_comboBox->addItem(info.portName());//查找可用的端口
    }
    currentIndex=ui->serialPort_comboBox->findText(temp);
    if(currentIndex!=-1)ui->serialPort_comboBox->setCurrentIndex(currentIndex);

    if (!findPortTimer.isActive())
        findPortTimer.start(findPortTimerPeriod);
}

//设置串口
void MainWindow::setPortParameter()
{
    serialPort.close();//先关上
    serialPort.setPortName(ui->serialPort_comboBox->currentText());
    serialPort.setParity(QSerialPort::EvenParity);
    int serialPortBaudRate = 2400;
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
