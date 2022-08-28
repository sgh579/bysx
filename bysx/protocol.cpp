#include "protocol.h"
#include <QCoreApplication>
protocol::protocol(QObject *parent)
    : QObject(parent)
    , get_485_message(false)
{
    qDebug()<<"here are protocol"<<endl;
}

//解读多个回复帧
bool protocol::decode(const QByteArray m_readData)
{
    QByteArray temp_readData = m_readData;
    qDebug()<<"decode start"<<endl;
    qDebug()<<"decode byte array:"<<temp_readData.toHex()<<endl;
    int cache_length = temp_readData.length();
    qDebug()<<"cache_length :"<<cache_length<<endl;

    int frame_start_index = 0;

    //debug
//    if((uint8_t)m_readData[0] == 0xfe)qDebug()<<"m_readData[0] == 0xfe ok"<<endl;
//    else qDebug()<<"m_readData[0] == 0xfe not ok"<<endl;
//     qDebug()<<"m_readData[0] ="<<(uint8_t)m_readData[0]<<endl;

    while(cache_length>8){

        //找出一个帧
        for(int i =0;i<cache_length-8;i++){
            if(((uint8_t)temp_readData[i] == 0x68) && (cache_length>i+8) && ((uint8_t)temp_readData[i+7] == 0x68)){

                frame_start_index = i;
                break;
            }
        }


        addr = temp_readData.mid(frame_start_index+1,6);

        ctrl_code =temp_readData[frame_start_index+8];
        data_length =temp_readData[frame_start_index+9];
        if((uint8_t)temp_readData[frame_start_index+11+data_length] != 0x16)return false;//说明传输有错误，整个重来
        //qDebug()<<"data_length"<<data_length<<endl;
        if(data_length>0){
            data = temp_readData.mid(frame_start_index+10,data_length);
            for(int i=0;i<data_length;i++){
                data[i]=data[i]-0x33;
            }
        }
        else data.resize(0);
        //    char CS = m_readData[frame_start_index+10+data_length];
        //校验暂时省略
        decode_frame(data);//找到一帧，就去读帧，保存到equipmemnt里面

        printMember();

        //把暂存区一开始到这一帧结束的东西全部删除
        temp_readData.remove(0,frame_start_index+12+data_length);
        cache_length = temp_readData.length();
        frame_start_index = 0;
    }
    return true;
}

void protocol::printMember(){
    qDebug()<<"***************printMember****************"<<endl;
    qDebug()<<"addr"<<addr.toHex()<<endl;
    qDebug()<<"ctrl_code"<<ctrl_code<<endl;
    qDebug()<<"data length"<<data_length<<endl;
    qDebug()<<"data"<<data.toHex()<<endl;
    qDebug()<<"*****************************************"<<endl;
}


//以一定时间间隔发出请求信息，将所有得到的信息放在一个地方，最后统一解码
void protocol::talk()
{

}

bool protocol::decode_frame(const QByteArray data)
{
    qDebug()<<"decode_frame"<<endl;
    QByteArray dataID = data.mid(0,4);

    //时间
    if(((uint8_t)dataID[0] == 0x01) && ((uint8_t)dataID[1] == 0x01) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[4] == 0x04)){

    }

    //日期
    if(((uint8_t)dataID[0] == 0x01) && ((uint8_t)dataID[1] == 0x01) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[4] == 0x04)){

    }

    //表号
    if(((uint8_t)dataID[0] == 0x01) && ((uint8_t)dataID[1] == 0x01) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[4] == 0x04)){

    }

    //时间
    if(((uint8_t)dataID[0] == 0x01) && ((uint8_t)dataID[1] == 0x01) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[4] == 0x04)){

    }

    return true;
}
