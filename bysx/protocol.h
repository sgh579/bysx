#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <QByteArray>
#include <QString>
#include <QDebug>

#include <QObject>
#include "equipment.h"
#include "reader.h"
#include "writer.h"



#include<QTime>

class protocol : public QObject
{
    Q_OBJECT
public:
    explicit protocol(QObject *parent = nullptr);
//    ~protocol();
    bool getAddress();
    void code();
    void talk(writer *serialPortWriter,reader *serialPortReader);//包含一次完整的询问
    void my_sleep(int ms);
public slots:
    bool decode(const QByteArray m_readData);
    void printMember();
    bool decode_frame(const QByteArray data);

public:
    uint8_t ctrl_code;//控制码C
    int data_length;
    QByteArray data;
    QByteArray addr;
    bool get_485_message;
    equipment *current_equ;


};

#endif // PROTOCOL_H
