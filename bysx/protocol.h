#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <reader.h>
#include <QObject>
class protocol : public QObject
{
    Q_OBJECT
public:
    explicit protocol(QObject *parent = nullptr);
//    ~protocol();
    void getAddress();
    void code();
public slots:
    bool decode(const QByteArray m_readData);
    void printMember();

private:
    uint8_t ctrl_code;//控制码C
    int data_length;
    QByteArray data;
    QByteArray addr;



};

#endif // PROTOCOL_H
