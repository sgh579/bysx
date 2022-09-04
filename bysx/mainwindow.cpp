#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPortInfo>

#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include <QAxObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_standardOutput(stdout)
    , findPortTimerPeriod(1000)
    , auto_update_interval_period(60000)
{
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui_equ = new equipment();
    ui_pro = new protocol();

    m_standardOutput<<"hello bysx,here is mainwindow()"<<endl;

    //debug按钮，连接回调函数
    connect(ui->debugButton,&QPushButton::clicked,this,&MainWindow::debugButtonCallback);

    //定时刷新串口
    connect(&findPortTimer,&QTimer::timeout,this,&MainWindow::findPort);
    findPortTimer.start(findPortTimerPeriod);

    //连接串口
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::setPortParameter);

    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::tableToExcel);

    //以下为变量导入tableWidget

    //自动更新
    connect(&auto_update_Timer,&QTimer::timeout,this,&MainWindow::auto_update_data);



//    tableToExcel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//由debug按钮触发的 执行一定函数功能
void MainWindow::debugButtonCallback()
{

    //serialPortWriter->write();
//    QByteArray debug_read_data = QByteArray::fromHex("fefe681855600600006893064b88933933334116");
//    if(ui_pro->decode(debug_read_data) == true)qDebug()<<"decode sucessfull"<<endl;
//    else qDebug()<<"decode fail"<<endl;

//    serialPortReader->emit_debug_signal();

//    ui_pro->talk(this->serialPortWriter,this->serialPortReader);

    //ui_pro->printMember();

    //i->tableWidget->setItem(0,0,new QTableWidgetItem(tr("hello")));

//    fill_the_table();

}

//由定时器自动触发的寻找串口
void MainWindow::findPort()
{
    QString temp=ui->serialPort_comboBox->currentText();
    int currentIndex=0;
    int intNum=0;
    intNum = ui->serialPort_comboBox->count();
    for(;intNum>0;intNum--)ui->serialPort_comboBox->removeItem(intNum-1);
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
    {
        ui->serialPort_comboBox->addItem(info.portName());//查找可用的端口
    }
    currentIndex=ui->serialPort_comboBox->findText(temp);
    if(currentIndex!=-1)ui->serialPort_comboBox->setCurrentIndex(currentIndex);

    if (!findPortTimer.isActive())
        findPortTimer.start(findPortTimerPeriod);
}

//设置串口
void MainWindow::setPortParameter()
{
    serialPort.close();//先关上
    serialPort.setPortName(ui->serialPort_comboBox->currentText());
    serialPort.setParity(QSerialPort::EvenParity);
//    int serialPortBaudRate = 2400;
    int serialPortBaudRatelist[] = {2400,1200,4800,9600,14400,19200};
    int serialPortBaudRatelist_index = 0;

    while(true)
    {
        serialPort.setBaudRate(serialPortBaudRatelist[serialPortBaudRatelist_index]);
        serialPortBaudRatelist_index++;
        if(serialPortBaudRatelist_index==6)break;

        if(!serialPort.open(QIODevice::ReadWrite))
        {
            qDebug()<<tr("can't open %1 ,error code %2")
                    .arg(serialPort.portName()).arg(serialPort.error())<<endl;
//            return;
        }
        else
        {
            qDebug()<<tr(" open %1 successfully")
                    .arg(serialPort.portName())<<endl;
            qDebug()<<"波特率匹配成功："<<serialPortBaudRatelist[serialPortBaudRatelist_index-1]<<endl;
            break;
        }
    }

    serialPortWriter = new writer(&serialPort);
    m_standardOutput<<"writer object built successfully"<<endl;
    serialPortWriter->write();

    serialPortReader = new reader(&serialPort);
    connect(serialPortReader,&reader::read_ready_decode_signal,ui_pro,&protocol::decode);

    //串口连接了，才能自动更新
    auto_update_Timer.start(auto_update_interval_period);

    //确定端口了直接talk
    ui_pro->talk(this->serialPortWriter,this->serialPortReader);
    fill_the_table();

}

void MainWindow::tableToExcel()
{
    //获取保存路径
        QString filepath=QFileDialog::getSaveFileName(this,tr("Save"),".",tr(" (*.xlsx)"));
        if(!filepath.isEmpty()){
            QAxObject *excel = new QAxObject(this);
            //连接Excel控件
            excel->setControl("Excel.Application");
            //不显示窗体
            excel->dynamicCall("SetVisible (bool Visible)","false");
            //不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
            excel->setProperty("DisplayAlerts", false);
            //获取工作簿集合
            QAxObject *workbooks = excel->querySubObject("WorkBooks");
            //新建一个工作簿
            workbooks->dynamicCall("Add");
            //获取当前工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
            //获取工作表集合
            QAxObject *worksheets = workbook->querySubObject("Sheets");
            //获取工作表集合的工作表1，即sheet1
            worksheet = worksheets->querySubObject("Item(int)",1);

//          以下为tableWidget_1的内容

            int tableR = ui->tableWidget->rowCount();
            int tableC = ui->tableWidget->columnCount();

            //获取表头写做第一行
//            for (int i=0; i<tableC; i++) {
//                if ( ui->tableWidget->horizontalHeaderItem(i) != NULL ) {
//                    this->SetCellData(1, i+1, ui->tableWidget->horizontalHeaderItem(i)->text());
//                }
//            }

            //写数据
            for (int i=0; i<tableR; i++) {
                for (int j=0; j<tableC; j++) {
                    if ( ui->tableWidget->item(i,j) != NULL ){
                        this->SetCellData(i+1, j+1, ui->tableWidget->item(i,j)->text());
                    }
                }
            }

            //          以下为tableWidget_2的内容

                        int tableR2 = ui->tableWidget_2->rowCount();
                        int tableC2 = ui->tableWidget_2->columnCount();

                        //获取表头写做第一行
                        for (int i=0; i<tableC2; i++) {
                            if ( ui->tableWidget_2->horizontalHeaderItem(i) != NULL ) {
                                this->SetCellData(8, i+1, ui->tableWidget_2->horizontalHeaderItem(i)->text());
                            }
                        }

                        //写数据
                        for (int i=0; i<tableR2; i++) {
                            for (int j=0; j<tableC2; j++) {
                                if ( ui->tableWidget_2->item(i,j) != NULL ){
                                    this->SetCellData(i+9, j+1, ui->tableWidget_2->item(i,j)->text());
                                }
                            }
                        }

            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
            workbook->dynamicCall("Close()");//关闭工作簿
            excel->dynamicCall("Quit()");//关闭excel
            delete excel;
            excel=NULL;
           }

  }

bool MainWindow::SetCellData(int row, int column, QVariant data)
{
    bool op = false;

    QAxObject *cell = worksheet->querySubObject("Cells(int,int)",row,column);//获取单元格对象
    if ( cell ) {
        QString strData = data.toString(); //excel 居然只能插入字符串和整型，浮点型无法插入
        cell->dynamicCall("SetValue(const QVariant&)",strData); //修改单元格的数据
        op = true;
    }else {
        op = false;
    }

    return op;
}

void MainWindow::fill_the_table()
{
    //t1
    this->ui_pro->current_equ->ID = "6605518";
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(this->ui_pro->current_equ->ID));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem(this->ui_pro->current_equ->ratedVoltage));
    ui->tableWidget->setItem(1,3,new QTableWidgetItem(this->ui_pro->current_equ->ratedCurrent));
    ui->tableWidget->setItem(4,1,new QTableWidgetItem(this->ui_pro->current_equ->equ_date + this->ui_pro->current_equ->equ_time));
    ui->tableWidget->setItem(2,3,new QTableWidgetItem(this->ui_pro->current_equ->constant_active));
    ui->tableWidget->setItem(3,3,new QTableWidgetItem(this->ui_pro->current_equ->level_active));

    ui->tableWidget->setItem(1,1,new QTableWidgetItem("DL/T645-2007"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("2400"));
    ui->tableWidget->setItem(3,1,new QTableWidgetItem("18 55 60 06 00 00"));



    //t2
    ui->tableWidget_2->setItem(0,1,new QTableWidgetItem(this->ui_pro->current_equ->all_pos_active));
    ui->tableWidget_2->setItem(1,1,new QTableWidgetItem(this->ui_pro->current_equ->jian_pos_active));
    ui->tableWidget_2->setItem(2,1,new QTableWidgetItem(this->ui_pro->current_equ->feng_pos_active));
    ui->tableWidget_2->setItem(3,1,new QTableWidgetItem(this->ui_pro->current_equ->ping_pos_active));
    ui->tableWidget_2->setItem(4,1,new QTableWidgetItem(this->ui_pro->current_equ->gu_pos_active));

    ui->tableWidget_2->setItem(0,3,new QTableWidgetItem(this->ui_pro->current_equ->all_neg_active));
    ui->tableWidget_2->setItem(1,3,new QTableWidgetItem(this->ui_pro->current_equ->jian_neg_active));
    ui->tableWidget_2->setItem(2,3,new QTableWidgetItem(this->ui_pro->current_equ->feng_neg_active));
    ui->tableWidget_2->setItem(3,3,new QTableWidgetItem(this->ui_pro->current_equ->ping_neg_active));
    ui->tableWidget_2->setItem(4,3,new QTableWidgetItem(this->ui_pro->current_equ->gu_neg_active));


}


void MainWindow::auto_update_data()
{
    ui_pro->talk(this->serialPortWriter,this->serialPortReader);
    fill_the_table();
    auto_update_Timer.start(auto_update_interval_period);
}














