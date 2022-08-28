#include "reader.h"
#include <QDebug>
#include <QCoreApplication>
#include <QTime>
#include "mainwindow.h"


reader::reader(QSerialPort *serialPort, QObject *parent)
    : QObject(parent)
    , m_serialPort(serialPort)
    , m_standardOutput(stdout)
    , decodeTimerPeriod(100)
    , printReadDataPeriod(1000)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &reader::handleReadyRead);
    connect(m_serialPort, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &reader::handleError);
    connect(&m_timer, &QTimer::timeout, this, &reader::handleTimeout);

    qDebug()<<"here are reader()"<<endl;
    m_timer.start(printReadDataPeriod);




}

reader::~reader()
{
}

void reader::handleReadyRead()
{
    m_readData.append(m_serialPort->readAll());//把读到的字符串放到m_readData后面
    //m_standardOutput<<m_readData.toHex() << endl;//通过标准输出把读到的在终端里输出
    if (!m_timer.isActive())
        m_timer.start(printReadDataPeriod);
}

void reader::handleTimeout()
{
    if (m_readData.isEmpty()) {
        m_standardOutput << QObject::tr("No data was currently available for reading from port %1").arg(m_serialPort->portName()) << endl;
        //qDebug()<<QObject::tr("No data was currently available for reading from port %1").arg(m_serialPort->portName()) << endl;
    } else {
        m_standardOutput << QObject::tr("Data successfully received from port %1").arg(m_serialPort->portName()) << endl;
//        qDebug()<< QObject::tr("Data successfully received from port %1").arg(m_serialPort->portName()) << endl;
        m_standardOutput << m_readData << endl;//通过标准输出把读到的在终端里输出


//        qDebug()<< m_readData << endl;//通过标准输出把读到的在终端里输出
//        qDebug()<< m_readData.toHex() << endl;//通过标准输出把读到的在终端里输出
    }

    //QCoreApplication::quit();

}




void reader::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        m_standardOutput << QObject::tr("An I/O error occurred while reading the data from port %1, error: %2").arg(m_serialPort->portName()).arg(m_serialPort->errorString()) << endl;
        QCoreApplication::exit(1);
    }
}














