#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QStringList>
#include <QTimer>
#include <QComboBox>

#include <QTextStream>
#include <QFile>
#include <QStringList>
#include "reader.h"
#include <QDebug>
#include "writer.h"


#include "protocol.h"
#include "equipment.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QPushButton;
class QLabel;
class QComboBox;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QString serialPortName;
    QSerialPort serialPort;
    reader *serialPortReader;
    writer *serialPortWriter;
    QTextStream m_standardOutput;
    protocol *ui_pro;
    equipment *ui_equ;

public slots:
    void debugButtonCallback();
    void call_decode(QByteArray m_readData);

};
#endif // MAINWINDOW_H
