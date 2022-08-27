/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_2;
    QTableWidget *tableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *debugButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1071, 610);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\350\257\273\345\217\226\346\225\260\346\215\256\345\272\223.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget_2 = new QTableWidget(centralwidget);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget_2->rowCount() < 6)
            tableWidget_2->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(238, 238, 224, 255));
        brush1.setStyle(Qt::SolidPattern);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        __qtablewidgetitem10->setBackground(brush1);
        __qtablewidgetitem10->setForeground(brush);
        tableWidget_2->setItem(0, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        __qtablewidgetitem11->setBackground(brush1);
        tableWidget_2->setItem(0, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        __qtablewidgetitem12->setBackground(brush1);
        tableWidget_2->setItem(1, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        __qtablewidgetitem13->setBackground(brush1);
        tableWidget_2->setItem(1, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font);
        __qtablewidgetitem14->setBackground(brush1);
        tableWidget_2->setItem(2, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font);
        __qtablewidgetitem15->setBackground(brush1);
        tableWidget_2->setItem(2, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font);
        __qtablewidgetitem16->setBackground(brush1);
        tableWidget_2->setItem(3, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font);
        __qtablewidgetitem17->setBackground(brush1);
        tableWidget_2->setItem(3, 2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font);
        __qtablewidgetitem18->setBackground(brush1);
        tableWidget_2->setItem(4, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font);
        __qtablewidgetitem19->setBackground(brush1);
        tableWidget_2->setItem(4, 2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font);
        __qtablewidgetitem20->setBackground(brush1);
        tableWidget_2->setItem(5, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font);
        __qtablewidgetitem21->setBackground(brush1);
        tableWidget_2->setItem(5, 2, __qtablewidgetitem21);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_2->sizePolicy().hasHeightForWidth());
        tableWidget_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        tableWidget_2->setFont(font1);
        tableWidget_2->horizontalHeader()->setVisible(false);
        tableWidget_2->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget_2);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(true);
        font2.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font2);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font2);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font2);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font2);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem25);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setBold(true);
        font3.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font3);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font3);
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font3);
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font3);
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font3);
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem30);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setFont(font1);
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setLineWidth(1);
        tableWidget->setMidLineWidth(1);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setAutoScroll(true);
        tableWidget->setAutoScrollMargin(16);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFrameShape(QFrame::StyledPanel);

        horizontalLayout->addWidget(label_2);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy3);
        pushButton_5->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\344\270\200\351\224\256\345\220\214\346\255\245.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon1);
        pushButton_5->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(pushButton_5);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/EXEL.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(pushButton);

        debugButton = new QPushButton(widget);
        debugButton->setObjectName(QStringLiteral("debugButton"));

        horizontalLayout->addWidget(debugButton);


        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1071, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->verticalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->verticalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->item(0, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\350\241\250\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->item(0, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "\351\242\235\345\256\232\347\224\265\345\216\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->item(1, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "\351\200\232\344\277\241\350\247\204\347\272\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->item(1, 2);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\351\242\235\345\256\232\347\224\265\346\265\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->item(2, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->item(2, 2);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\346\234\211\345\212\237\345\270\270\346\225\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_2->item(3, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\351\200\232\344\277\241\345\234\260\345\235\200", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_2->item(3, 2);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "\346\234\211\345\212\237\347\255\211\347\272\247", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_2->item(4, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\350\241\250\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_2->item(4, 2);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "\346\227\240\345\212\237\345\270\270\346\225\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_2->item(5, 2);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "\346\227\240\345\212\237\347\255\211\347\272\247", Q_NULLPTR));
        tableWidget_2->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "\346\255\243\345\220\221\346\234\211\345\212\237\n"
"[kWh]", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "\346\255\243\345\220\221\346\227\240\345\212\237\n"
"[kvarh]", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "\345\217\215\345\220\221\346\234\211\345\212\237\n"
"[kWh]", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "\345\217\215\345\220\221\346\227\240\345\212\237\n"
"[kvarh]", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "\346\200\273", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "\345\260\226", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "\345\263\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "\345\271\263", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "\350\260\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\350\257\273\350\241\250\346\210\220\345\212\237", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\246\202\351\234\200\351\200\211\346\213\251\347\211\271\345\256\232\346\227\266\351\227\264\346\256\265\350\257\273\345\217\226\357\274\214\350\257\267\345\234\250\346\255\244\350\276\223\345\205\245\346\227\266\351\227\264", Q_NULLPTR));
        pushButton_5->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\345\210\260exel", Q_NULLPTR));
        debugButton->setText(QApplication::translate("MainWindow", "debug", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
