#ifndef WRITER_H
#define WRITER_H

#include <QtSerialPort/QSerialPort>

#include <QTextStream>
#include <QTimer>
#include <QByteArray>
#include <QObject>


class writer : public QObject
{
    Q_OBJECT
public:
    explicit writer(QSerialPort *serialPort, QObject *parent = nullptr);
    ~writer();



    void write();
private slots:
    void handleBytesWritten(qint64 bytes);
    void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);


public:
    QSerialPort     *m_serialPort;
    QByteArray      m_writeData;
    QTextStream     m_standardOutput;
    qint64          m_bytesWritten;
    QTimer          m_timer;


};


#endif // WRITER_H
