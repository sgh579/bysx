#include "protocol.h"
#include <QCoreApplication>
protocol::protocol(QObject *parent)
    : QObject(parent)
{
    qDebug()<<"here are protocol"<<endl;
}

bool protocol::decode(const QByteArray m_readData)
{
    qDebug()<<"decode start"<<endl;
    qDebug()<<"decode byte array:"<<m_readData.toHex()<<endl;
    int cache_length = m_readData.length();
    qDebug()<<"cache_length :"<<cache_length<<endl;
    bool find_frame_flag = 0;
    int frame_start_index = 0;

    //debug
//    if((uint8_t)m_readData[0] == 0xfe)qDebug()<<"m_readData[0] == 0xfe ok"<<endl;
//    else qDebug()<<"m_readData[0] == 0xfe not ok"<<endl;
//     qDebug()<<"m_readData[0] ="<<(uint8_t)m_readData[0]<<endl;


    for(int i =0;i<cache_length-8;i++){
        if(((uint8_t)m_readData[i] == 0x68) && (cache_length>i+8) && ((uint8_t)m_readData[i+7] == 0x68)){

            frame_start_index = i;
            find_frame_flag = true;
            break;
        }
        find_frame_flag = false;
    }
    //qDebug()<<"index:"<<frame_start_index<<endl;
    if(find_frame_flag == false)return find_frame_flag;

    addr = m_readData.mid(frame_start_index+1,6);

    ctrl_code =m_readData[frame_start_index+8];
    data_length =m_readData[frame_start_index+9];
    qDebug()<<"data_length"<<data_length<<endl;
    if(data_length>0){
        data = m_readData.mid(frame_start_index+10,data_length);
        for(int i=0;i<data_length;i++){
            data[i]=data[i]-0x33;
        }
    }
    else data.resize(0);
//    char CS = m_readData[frame_start_index+10+data_length];
    //校验暂时省略

    if(m_readData[frame_start_index+11+data_length] == 0x16){
        find_frame_flag = true;
    }
    else
    {
        find_frame_flag = false;
    }

    return find_frame_flag;
}

void protocol::printMember(){
    qDebug()<<"addr"<<addr.toHex()<<endl;
    qDebug()<<"ctrl_code"<<ctrl_code<<endl;
    qDebug()<<"data length"<<data_length<<endl;
    qDebug()<<"data"<<data.toHex()<<endl;

}
