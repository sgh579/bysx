#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QString>
#include <QByteArray>


class equipment
{
public:
    equipment();
    QString ID;//表号 12位
    //时间 找找时间相关的变量
    QByteArray addr;//通信地址
    QString ratedVoltage;//额定电压
    QString ratedCurrent;//额定电流

    float all_pos_active;//正向有功 总
    float jian_pos_active;//正向有功 尖
    float feng_pos_active;//正向有功 锋
    float ping_pos_active;//正向有功 平
    float gu_pos_active;//正向有功 谷

    float all_neg_active;//反向有功 总
    float jian_neg_active;//反向有功 尖
    float feng_neg_active;//反向有功 锋
    float ping_neg_active;//反向有功 平
    float gu_neg_active;//反向有功 谷

    float all_pos_reactive;//正向无功 总
    float jian_pos_reactive;//正向无功 尖
    float feng_pos_reactive;//正向无功 锋
    float ping_pos_reactive;//正向无功 平
    float gu_pos_reactive;//正向无功 谷

    float all_neg_reactive;//反向无功 总
    float jian_neg_reactive;//反向无功 尖
    float feng_neg_reactive;//反向无功 锋
    float ping_neg_reactive;//反向无功 平
    float gu_neg_reactive;//正向有功 谷


};

#endif // EQUIPMENT_H
