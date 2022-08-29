#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include <QAxObject>

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
    QAxObject *worksheet;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void tableToExcel();
    bool SetCellData(int row, int column, QVariant data);
    void fill_the_table();


private:
    Ui::MainWindow *ui;
    QString serialPortName;
    QSerialPort serialPort;
    reader *serialPortReader;
    writer *serialPortWriter;
    QTextStream m_standardOutput;
    protocol *ui_pro;
    int findPortTimerPeriod;
    QTimer findPortTimer;


public slots:
    void debugButtonCallback();
    void findPort();//主动更新可用串口
    void setPortParameter();//设置要打开的串口参数，并打开，实例化writer,reader对象，开始接收


};
#endif // MAINWINDOW_H
