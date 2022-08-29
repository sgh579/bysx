#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <reader.h>
#include <QObject>
#include "equipment.h"
class protocol : public QObject
{
    Q_OBJECT
public:
    explicit protocol(QObject *parent = nullptr);
//    ~protocol();
    bool getAddress();
    void code();
    void talk();//包含一次完整的询问
public slots:
    bool decode(const QByteArray m_readData);
    void printMember();
    bool decode_frame(const QByteArray data);

private:
    uint8_t ctrl_code;//控制码C
    int data_length;
    QByteArray data;
    QByteArray addr;
    bool get_485_message;
    equipment *current_equ;


};

#endif // PROTOCOL_H
