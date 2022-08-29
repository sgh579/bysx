#include "protocol.h"
#include <QCoreApplication>
protocol::protocol(QObject *parent)
    : QObject(parent)
    , get_485_message(false)
{
    current_equ = new equipment();;
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

//data 就是数据区域的字节串 返回值就是这一次读取是否成功
bool protocol::decode_frame(const QByteArray data)
{
    qDebug()<<"decode_frame"<<endl;
    QByteArray dataID = data.mid(0,4);

    //时间 02 01 00 04
    if(((uint8_t)dataID[0] == 0x02) && ((uint8_t)dataID[1] == 0x01) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[3] == 0x04)){
        if(data.size()<7)return false;
        QByteArray hh;
        hh[0]= data[6];
        QByteArray mm;
        mm[0]= data[5];
        QByteArray ss;
        ss[0]= data[4];
        this->current_equ->equ_time =hh.toHex() +" "+ mm.toHex() +" " + ss.toHex();
    }

    //日期 01 01 00 04
    else if(((uint8_t)dataID[0] == 0x01) && ((uint8_t)dataID[1] == 0x01) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[3] == 0x04)){
        if(data.size()<8)return false;
        QByteArray yy;
        yy[0]= data[6];
        QByteArray mm;
        mm[0]= data[5];
        QByteArray dd;
        dd[0]= data[4];
        QByteArray ww;
        ww[0]= data[4];

        this->current_equ->equ_time =yy.toHex() +"年"+ mm.toHex() +"月" + dd.toHex()+"日"+" 星期"+ww.toHex();
    }

    //表号 02 04  00 04
    else if(((uint8_t)dataID[0] == 0x02) && ((uint8_t)dataID[1] == 0x04) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[3] == 0x04)){
        if(data.size()<4+6)return false;
        //表号就是通信地址
    }

    //额定电压 04 04 00 04
    else if(((uint8_t)dataID[0] == 0x04) && ((uint8_t)dataID[1] == 0x04) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[3] == 0x04)){
        if(data.size()<4+6)return false;
        QByteArray temp_ba;
        temp_ba.resize(6);
        temp_ba[0] = data[9];
        temp_ba[1] = data[8];
        temp_ba[2] = data[7];
        temp_ba[3] = data[6];
        temp_ba[4] = data[5];
        temp_ba[5] = data[4];
        this->current_equ->ratedVoltage = temp_ba;
    }

    //额定电流 05 04 00 04
    else if(((uint8_t)dataID[0] == 0x05) && ((uint8_t)dataID[1] == 0x04) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[3] == 0x04)){
        if(data.size()<4+6)return false;
        QByteArray temp_ba;
        temp_ba.resize(6);
        temp_ba[0] = data[9];
        temp_ba[1] = data[8];
        temp_ba[2] = data[7];
        temp_ba[3] = data[6];
        temp_ba[4] = data[5];
        temp_ba[5] = data[4];
        this->current_equ->ratedCurrent = temp_ba;
    }

    //有功常数 09 04 00 04
    else if(((uint8_t)dataID[0] == 0x09) && ((uint8_t)dataID[1] == 0x04) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[3] == 0x04)){
        if(data.size()<4+3)return false;
        QByteArray temp_ba;
        temp_ba.resize(3);
        QByteArray constant_ba = data.mid(4,3);
        for(int i=0;i<constant_ba.size();i++)
        {
            temp_ba[i]= constant_ba[constant_ba.size()-1-i];
        }
        this->current_equ->constant_active = temp_ba.toHex();
    }

    //有功等级 07 04 00 04
    else if(((uint8_t)dataID[0] == 0x07) && ((uint8_t)dataID[1] == 0x04) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[3] == 0x04)){
        int useful_data_len = 4;
        if(data.size()<4+useful_data_len)return false;
        QByteArray temp_ba;
        temp_ba.resize(useful_data_len);
        QByteArray constant_ba = data.mid(4,useful_data_len);
        for(int i=0;i<constant_ba.size();i++)
        {
            temp_ba[i]= constant_ba[constant_ba.size()-1-i];
        }
        this->current_equ->level_active = temp_ba;
    }

    // 正 有 00 00-04 01 00 第2字节从小到大依次是总 尖 峰 平 谷
    else if(((uint8_t)dataID[0] == 0x00)  && ((uint8_t)dataID[1]<=4)&& ((uint8_t)dataID[2] == 0x01) && ((uint8_t)dataID[3] == 0x00)){
        int useful_data_len = 4;
        if(data.size()<4+useful_data_len)return false;
        QByteArray temp_ba;
        temp_ba.resize(useful_data_len);
        QByteArray constant_ba = data.mid(4,useful_data_len);
        for(int i=0;i<constant_ba.size();i++)
        {
            temp_ba[i]= constant_ba[constant_ba.size()-1-i];
        }
        switch((uint8_t)dataID[2]){
            case 0:this->current_equ->all_pos_active = temp_ba.mid(0,3).toHex()+"."+temp_ba.mid(3,1).toHex();
            break;

            case 1:this->current_equ->jian_pos_active = temp_ba.mid(0,3).toHex()+"."+temp_ba.mid(3,1).toHex();
            break;

            case 2:this->current_equ->feng_pos_active = temp_ba.mid(0,3).toHex()+"."+temp_ba.mid(3,1).toHex();
            break;

            case 3:this->current_equ->ping_pos_active = temp_ba.mid(0,3).toHex()+"."+temp_ba.mid(3,1).toHex();
            break;

            case 4:this->current_equ->gu_pos_active = temp_ba.mid(0,3).toHex()+"."+temp_ba.mid(3,1).toHex();
            break;
        }
    }

    // 反 有 00 00-04 02 00 第2字节从小到大依次是总 尖 峰 平 谷
    else if(((uint8_t)dataID[0] == 0x00) && ((uint8_t)dataID[1] <=4) && ((uint8_t)dataID[2] == 0x02)&& ((uint8_t)dataID[3] == 0x00)){
        int useful_data_len = 4;
        if(data.size()<4+useful_data_len)return false;
        QByteArray temp_ba;
        temp_ba.resize(useful_data_len);
        QByteArray constant_ba = data.mid(4,useful_data_len);
        for(int i=0;i<constant_ba.size();i++)
        {
            temp_ba[i]= constant_ba[constant_ba.size()-1-i];
        }
        switch((uint8_t)dataID[2]){
            case 0:this->current_equ->all_neg_active = temp_ba.mid(0,3).toHex()+"."+temp_ba.mid(3,1).toHex();
            break;

            case 1:this->current_equ->jian_neg_active = temp_ba.mid(0,3).toHex()+"."+temp_ba.mid(3,1).toHex();
            break;

            case 2:this->current_equ->feng_neg_active = temp_ba.mid(0,3).toHex()+"."+temp_ba.mid(3,1).toHex();
            break;

            case 3:this->current_equ->ping_neg_active = temp_ba.mid(0,3).toHex()+"."+temp_ba.mid(3,1).toHex();
            break;

            case 4:this->current_equ->gu_neg_active = temp_ba.mid(0,3).toHex()+"."+temp_ba.mid(3,1).toHex();
            break;
        }
    }
    else return false;


    return true;
}

bool protocol::getAddress()
{
    current_equ->addr = QByteArray::fromHex("18 55 60 06 00 00");
    return true;
}
