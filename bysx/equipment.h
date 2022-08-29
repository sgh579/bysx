#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QString>
#include <QByteArray>


class equipment
{
public:
    equipment();
    QString ID;//表号 12位

    QString equ_time;// ok
    QByteArray addr;//通信地址 ok
    QString ratedVoltage;//额定电压 ok
    QString ratedCurrent;//额定电流 ok
    QString constant_active;//有功常数 ok
    QString constant_reactive;//无功常数
    QString level_active;//有功等级 ok
    QString level_reactive;//无功等级

    //ok
    QString all_pos_active;//正向有功 总
    QString jian_pos_active;//正向有功 尖
    QString feng_pos_active;//正向有功 锋
    QString ping_pos_active;//正向有功 平
    QString gu_pos_active;//正向有功 谷

    //ok
    QString all_neg_active;//反向有功 总
    QString jian_neg_active;//反向有功 尖
    QString feng_neg_active;//反向有功 锋
    QString ping_neg_active;//反向有功 平
    QString gu_neg_active;//反向有功 谷

    QString all_pos_reactive;//正向无功 总
    QString jian_pos_reactive;//正向无功 尖
    QString feng_pos_reactive;//正向无功 锋
    QString ping_pos_reactive;//正向无功 平
    QString gu_pos_reactive;//正向无功 谷

    QString all_neg_reactive;//反向无功 总
    QString jian_neg_reactive;//反向无功 尖
    QString feng_neg_reactive;//反向无功 锋
    QString ping_neg_reactive;//反向无功 平
    QString gu_neg_reactive;//正向有功 谷


};

#endif // EQUIPMENT_H
