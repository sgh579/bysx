
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
    int frame_count = 0;
    int decoded_frame_count = 0;

    //循环读帧
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
        if((uint8_t)temp_readData[frame_start_index+11+data_length] != 0x16)
        {
            qDebug()<<"尾16校验失败"<<endl;
//            return false;//说明传输有错误，整个重来
            break;
        }
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
        if(decode_frame(data))decoded_frame_count++;//找到一帧，就去读帧，保存到equipmemnt里面
        frame_count++;
        //printMember();

        //把这一帧东西全部删除
        temp_readData.remove(frame_start_index,12+data_length);
        qDebug()<<"删除一帧后temp_readData："<<temp_readData.toHex()<<endl;
        cache_length = temp_readData.length();
        frame_start_index = 0;
    }
    qDebug()<<"共找到帧数："<<frame_count<<endl;
    qDebug()<<"共解析成功帧数："<<decoded_frame_count<<endl;
    printMember();
    return true;
}

void protocol::printMember(){
    qDebug()<<"***************printMember****************"<<endl;
    qDebug()<<"addr"<<this->current_equ->addr.toHex()<<endl;
    qDebug()<<"equ_date "<<this->current_equ->equ_date<<endl;
    qDebug()<<"equ_time "<<this->current_equ->equ_time<<endl;
    qDebug()<<"ratedVoltage "<<this->current_equ->ratedVoltage<<endl;
    qDebug()<<"ratedCurrent "<<this->current_equ->ratedCurrent<<endl;
    qDebug()<<"constant_active "<<this->current_equ->constant_active<<endl;

    qDebug()<<"all_pos_active "<<this->current_equ->all_pos_active<<endl;
    qDebug()<<"jian_pos_active "<<this->current_equ->jian_pos_active<<endl;
    qDebug()<<"feng_pos_active "<<this->current_equ->feng_pos_active<<endl;
    qDebug()<<"ping_pos_active "<<this->current_equ->ping_pos_active<<endl;
    qDebug()<<"gu_pos_active "<<this->current_equ->gu_pos_active<<endl;

    qDebug()<<"all_neg_active "<<this->current_equ->all_neg_active<<endl;
    qDebug()<<"jian_neg_active "<<this->current_equ->jian_neg_active<<endl;
    qDebug()<<"feng_neg_active "<<this->current_equ->feng_neg_active<<endl;
    qDebug()<<"ping_neg_active "<<this->current_equ->ping_neg_active<<endl;
    qDebug()<<"gu_neg_active "<<this->current_equ->gu_neg_active<<endl;

    qDebug()<<"*****************************************"<<endl;
}


//以一定时间间隔发出请求信息，将所有得到的信息放在一个地方(reader::m_readData)，最后统一解码
void protocol::talk(writer *serialPortWriter,reader *serialPortReader)
{
    int sleep_interval = 333;

    QByteArray ba_ID = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 37 33 37 35 8e 16");
    QByteArray ba_date = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 34 34 33 37 8a 16");
    QByteArray ba_time = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 35 34 33 37 8b 16");
    QByteArray ba_U = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 37 37 33 37 90 16");
    QByteArray ba_A = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 38 37 33 37 91 16");
    QByteArray ba_constant_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 3c 37 33 37 95 16");
    QByteArray ba_level_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 3a 37 33 37 93 16");

    QByteArray ba_all_pos_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 33 33 34 33 85 16");
    QByteArray ba_jian_pos_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 33 34 34 33 86 16");
    QByteArray ba_feng_pos_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 33 35 34 33 87 16");
    QByteArray ba_ping_pos_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 33 36 34 33 88 16");
    QByteArray ba_gu_pos_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 33 37 34 33 89 16");

    QByteArray ba_all_neg_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 33 33 35 33 86 16");
    QByteArray ba_jian_neg_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 33 34 35 33 87 16");
    QByteArray ba_feng_neg_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 33 35 35 33 88 16");
    QByteArray ba_ping_neg_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 33 36 35 33 89 16");
    QByteArray ba_gu_neg_active = QByteArray::fromHex("68 18 55 60 06 00 00 68 11 04 33 37 35 33 8a 16");




    serialPortWriter->m_writeData =ba_ID;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_date;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_time;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_U;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_A;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_constant_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_level_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);


    serialPortWriter->m_writeData =ba_all_pos_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_jian_pos_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_feng_pos_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_ping_pos_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_gu_pos_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);


    serialPortWriter->m_writeData =ba_all_neg_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_jian_neg_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_feng_neg_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_ping_neg_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    serialPortWriter->m_writeData =ba_gu_neg_active;
    serialPortWriter->write();
    my_sleep(sleep_interval);

    decode(serialPortReader->m_readData);
    serialPortReader->m_readData.clear();

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
        this->current_equ->equ_time =hh.toHex() +":"+ mm.toHex() +":" + ss.toHex();
    }

    //日期 01 01 00 04
    else if(((uint8_t)dataID[0] == 0x01) && ((uint8_t)dataID[1] == 0x01) && ((uint8_t)dataID[2] == 0x00) && ((uint8_t)dataID[3] == 0x04)){
        if(data.size()<8)return false;
        QByteArray yy;
        yy[0]= data[7];
        QByteArray mm;
        mm[0]= data[6];
        QByteArray dd;
        dd[0]= data[5];
        QByteArray ww;
        ww[0]= data[4];

        this->current_equ->equ_date =yy.toHex() +"年"+ mm.toHex() +"月" + dd.toHex()+"日"+" (星期"+ww.toHex() + ") ";
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
        switch((uint8_t)dataID[1]){
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
        switch((uint8_t)dataID[1]){
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


void protocol::my_sleep(int ms)
{
    QTime interval_timer;
    interval_timer.start();
    while(interval_timer.elapsed()<ms)
    {
        QCoreApplication::processEvents();
    }
}
