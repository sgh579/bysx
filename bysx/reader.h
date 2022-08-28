#ifndef READER_H
#define READER_H

#include <QtSerialPort/QSerialPort>

#include <QTextStream>
#include <QTimer>
#include <QByteArray>
#include <QObject>

class reader : public QObject
{
    Q_OBJECT
public:
    explicit reader(QSerialPort *serialPort, QObject *parent = nullptr);
    ~reader();

signals:
    void read_ready_decode_signal(const QByteArray m_readData);

private slots:
    void handleReadyRead();
    void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort;
    QByteArray  m_readData;
    QTextStream m_standardOutput;
    QTimer      m_timer;

    QTimer decodeTimer;
    int decodeTimerPeriod;
    int printReadDataPeriod;






};

#endif // READER_H
