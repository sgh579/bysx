# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mainwindow.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *

import res_rc

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(726, 610)
        sizePolicy = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(MainWindow.sizePolicy().hasHeightForWidth())
        MainWindow.setSizePolicy(sizePolicy)
        MainWindow.setMaximumSize(QSize(16777215, 16777215))
        icon = QIcon()
        icon.addFile(u":/pic/\u8bfb\u53d6\u6570\u636e\u5e93.png", QSize(), QIcon.Normal, QIcon.Off)
        MainWindow.setWindowIcon(icon)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.verticalLayout = QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.tableWidget = QTableWidget(self.centralwidget)
        if (self.tableWidget.columnCount() < 4):
            self.tableWidget.setColumnCount(4)
        __qtablewidgetitem = QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(0, __qtablewidgetitem)
        __qtablewidgetitem1 = QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(1, __qtablewidgetitem1)
        __qtablewidgetitem2 = QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(2, __qtablewidgetitem2)
        __qtablewidgetitem3 = QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(3, __qtablewidgetitem3)
        if (self.tableWidget.rowCount() < 6):
            self.tableWidget.setRowCount(6)
        __qtablewidgetitem4 = QTableWidgetItem()
        self.tableWidget.setVerticalHeaderItem(0, __qtablewidgetitem4)
        __qtablewidgetitem5 = QTableWidgetItem()
        self.tableWidget.setVerticalHeaderItem(1, __qtablewidgetitem5)
        __qtablewidgetitem6 = QTableWidgetItem()
        self.tableWidget.setVerticalHeaderItem(2, __qtablewidgetitem6)
        __qtablewidgetitem7 = QTableWidgetItem()
        self.tableWidget.setVerticalHeaderItem(3, __qtablewidgetitem7)
        __qtablewidgetitem8 = QTableWidgetItem()
        self.tableWidget.setVerticalHeaderItem(4, __qtablewidgetitem8)
        __qtablewidgetitem9 = QTableWidgetItem()
        self.tableWidget.setVerticalHeaderItem(5, __qtablewidgetitem9)
        brush = QBrush(QColor(0, 0, 0, 255))
        brush.setStyle(Qt.NoBrush)
        brush1 = QBrush(QColor(238, 238, 224, 255))
        brush1.setStyle(Qt.SolidPattern)
        font = QFont()
        font.setBold(True)
        font.setWeight(75)
        __qtablewidgetitem10 = QTableWidgetItem()
        __qtablewidgetitem10.setFont(font);
        __qtablewidgetitem10.setBackground(brush1);
        __qtablewidgetitem10.setForeground(brush);
        self.tableWidget.setItem(0, 0, __qtablewidgetitem10)
        __qtablewidgetitem11 = QTableWidgetItem()
        self.tableWidget.setItem(0, 1, __qtablewidgetitem11)
        __qtablewidgetitem12 = QTableWidgetItem()
        __qtablewidgetitem12.setFont(font);
        __qtablewidgetitem12.setBackground(brush1);
        self.tableWidget.setItem(0, 2, __qtablewidgetitem12)
        __qtablewidgetitem13 = QTableWidgetItem()
        self.tableWidget.setItem(0, 3, __qtablewidgetitem13)
        __qtablewidgetitem14 = QTableWidgetItem()
        __qtablewidgetitem14.setFont(font);
        __qtablewidgetitem14.setBackground(brush1);
        self.tableWidget.setItem(1, 0, __qtablewidgetitem14)
        __qtablewidgetitem15 = QTableWidgetItem()
        self.tableWidget.setItem(1, 1, __qtablewidgetitem15)
        __qtablewidgetitem16 = QTableWidgetItem()
        __qtablewidgetitem16.setFont(font);
        __qtablewidgetitem16.setBackground(brush1);
        self.tableWidget.setItem(1, 2, __qtablewidgetitem16)
        __qtablewidgetitem17 = QTableWidgetItem()
        self.tableWidget.setItem(1, 3, __qtablewidgetitem17)
        __qtablewidgetitem18 = QTableWidgetItem()
        __qtablewidgetitem18.setFont(font);
        __qtablewidgetitem18.setBackground(brush1);
        self.tableWidget.setItem(2, 0, __qtablewidgetitem18)
        __qtablewidgetitem19 = QTableWidgetItem()
        self.tableWidget.setItem(2, 1, __qtablewidgetitem19)
        __qtablewidgetitem20 = QTableWidgetItem()
        __qtablewidgetitem20.setFont(font);
        __qtablewidgetitem20.setBackground(brush1);
        self.tableWidget.setItem(2, 2, __qtablewidgetitem20)
        __qtablewidgetitem21 = QTableWidgetItem()
        __qtablewidgetitem21.setFont(font);
        __qtablewidgetitem21.setBackground(brush1);
        self.tableWidget.setItem(3, 0, __qtablewidgetitem21)
        __qtablewidgetitem22 = QTableWidgetItem()
        __qtablewidgetitem22.setFont(font);
        __qtablewidgetitem22.setBackground(brush1);
        self.tableWidget.setItem(3, 2, __qtablewidgetitem22)
        __qtablewidgetitem23 = QTableWidgetItem()
        __qtablewidgetitem23.setFont(font);
        __qtablewidgetitem23.setBackground(brush1);
        self.tableWidget.setItem(4, 0, __qtablewidgetitem23)
        __qtablewidgetitem24 = QTableWidgetItem()
        self.tableWidget.setItem(4, 1, __qtablewidgetitem24)
        __qtablewidgetitem25 = QTableWidgetItem()
        __qtablewidgetitem25.setFont(font);
        __qtablewidgetitem25.setBackground(brush1);
        self.tableWidget.setItem(4, 2, __qtablewidgetitem25)
        __qtablewidgetitem26 = QTableWidgetItem()
        self.tableWidget.setItem(4, 3, __qtablewidgetitem26)
        __qtablewidgetitem27 = QTableWidgetItem()
        __qtablewidgetitem27.setFont(font);
        __qtablewidgetitem27.setBackground(brush1);
        self.tableWidget.setItem(5, 0, __qtablewidgetitem27)
        __qtablewidgetitem28 = QTableWidgetItem()
        __qtablewidgetitem28.setFont(font);
        __qtablewidgetitem28.setBackground(brush1);
        self.tableWidget.setItem(5, 2, __qtablewidgetitem28)
        __qtablewidgetitem29 = QTableWidgetItem()
        self.tableWidget.setItem(5, 3, __qtablewidgetitem29)
        self.tableWidget.setObjectName(u"tableWidget")
        sizePolicy1 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Expanding)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.tableWidget.sizePolicy().hasHeightForWidth())
        self.tableWidget.setSizePolicy(sizePolicy1)
        self.tableWidget.setMaximumSize(QSize(16777215, 16777215))
        font1 = QFont()
        font1.setFamily(u"\u6977\u4f53")
        self.tableWidget.setFont(font1)
        self.tableWidget.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.tableWidget.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.tableWidget.horizontalHeader().setVisible(False)
        self.tableWidget.verticalHeader().setVisible(False)

        self.verticalLayout.addWidget(self.tableWidget)

        self.tableWidget_2 = QTableWidget(self.centralwidget)
        if (self.tableWidget_2.columnCount() < 5):
            self.tableWidget_2.setColumnCount(5)
        font2 = QFont()
        font2.setFamily(u"\u5fae\u8f6f\u96c5\u9ed1")
        font2.setBold(True)
        font2.setWeight(75)
        __qtablewidgetitem30 = QTableWidgetItem()
        __qtablewidgetitem30.setFont(font2);
        self.tableWidget_2.setHorizontalHeaderItem(0, __qtablewidgetitem30)
        __qtablewidgetitem31 = QTableWidgetItem()
        __qtablewidgetitem31.setFont(font2);
        self.tableWidget_2.setHorizontalHeaderItem(1, __qtablewidgetitem31)
        __qtablewidgetitem32 = QTableWidgetItem()
        __qtablewidgetitem32.setFont(font2);
        self.tableWidget_2.setHorizontalHeaderItem(2, __qtablewidgetitem32)
        __qtablewidgetitem33 = QTableWidgetItem()
        __qtablewidgetitem33.setFont(font2);
        self.tableWidget_2.setHorizontalHeaderItem(3, __qtablewidgetitem33)
        __qtablewidgetitem34 = QTableWidgetItem()
        __qtablewidgetitem34.setFont(font2);
        self.tableWidget_2.setHorizontalHeaderItem(4, __qtablewidgetitem34)
        if (self.tableWidget_2.rowCount() < 5):
            self.tableWidget_2.setRowCount(5)
        font3 = QFont()
        font3.setFamily(u"\u5b8b\u4f53")
        font3.setBold(True)
        font3.setWeight(75)
        __qtablewidgetitem35 = QTableWidgetItem()
        __qtablewidgetitem35.setFont(font3);
        self.tableWidget_2.setVerticalHeaderItem(0, __qtablewidgetitem35)
        __qtablewidgetitem36 = QTableWidgetItem()
        __qtablewidgetitem36.setFont(font3);
        self.tableWidget_2.setVerticalHeaderItem(1, __qtablewidgetitem36)
        __qtablewidgetitem37 = QTableWidgetItem()
        __qtablewidgetitem37.setFont(font3);
        self.tableWidget_2.setVerticalHeaderItem(2, __qtablewidgetitem37)
        __qtablewidgetitem38 = QTableWidgetItem()
        __qtablewidgetitem38.setFont(font3);
        self.tableWidget_2.setVerticalHeaderItem(3, __qtablewidgetitem38)
        __qtablewidgetitem39 = QTableWidgetItem()
        __qtablewidgetitem39.setFont(font3);
        self.tableWidget_2.setVerticalHeaderItem(4, __qtablewidgetitem39)
        __qtablewidgetitem40 = QTableWidgetItem()
        self.tableWidget_2.setItem(0, 0, __qtablewidgetitem40)
        __qtablewidgetitem41 = QTableWidgetItem()
        self.tableWidget_2.setItem(0, 1, __qtablewidgetitem41)
        __qtablewidgetitem42 = QTableWidgetItem()
        self.tableWidget_2.setItem(0, 2, __qtablewidgetitem42)
        __qtablewidgetitem43 = QTableWidgetItem()
        self.tableWidget_2.setItem(0, 4, __qtablewidgetitem43)
        __qtablewidgetitem44 = QTableWidgetItem()
        self.tableWidget_2.setItem(1, 0, __qtablewidgetitem44)
        __qtablewidgetitem45 = QTableWidgetItem()
        self.tableWidget_2.setItem(1, 2, __qtablewidgetitem45)
        __qtablewidgetitem46 = QTableWidgetItem()
        self.tableWidget_2.setItem(1, 4, __qtablewidgetitem46)
        __qtablewidgetitem47 = QTableWidgetItem()
        self.tableWidget_2.setItem(2, 0, __qtablewidgetitem47)
        __qtablewidgetitem48 = QTableWidgetItem()
        self.tableWidget_2.setItem(2, 2, __qtablewidgetitem48)
        __qtablewidgetitem49 = QTableWidgetItem()
        self.tableWidget_2.setItem(2, 4, __qtablewidgetitem49)
        __qtablewidgetitem50 = QTableWidgetItem()
        self.tableWidget_2.setItem(3, 0, __qtablewidgetitem50)
        __qtablewidgetitem51 = QTableWidgetItem()
        self.tableWidget_2.setItem(3, 2, __qtablewidgetitem51)
        __qtablewidgetitem52 = QTableWidgetItem()
        self.tableWidget_2.setItem(3, 4, __qtablewidgetitem52)
        __qtablewidgetitem53 = QTableWidgetItem()
        self.tableWidget_2.setItem(4, 0, __qtablewidgetitem53)
        __qtablewidgetitem54 = QTableWidgetItem()
        self.tableWidget_2.setItem(4, 2, __qtablewidgetitem54)
        __qtablewidgetitem55 = QTableWidgetItem()
        self.tableWidget_2.setItem(4, 4, __qtablewidgetitem55)
        self.tableWidget_2.setObjectName(u"tableWidget_2")
        sizePolicy1.setHeightForWidth(self.tableWidget_2.sizePolicy().hasHeightForWidth())
        self.tableWidget_2.setSizePolicy(sizePolicy1)
        self.tableWidget_2.setFont(font1)
        self.tableWidget_2.setFrameShape(QFrame.StyledPanel)
        self.tableWidget_2.setLineWidth(1)
        self.tableWidget_2.setMidLineWidth(1)
        self.tableWidget_2.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.tableWidget_2.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.tableWidget_2.setSizeAdjustPolicy(QAbstractScrollArea.AdjustIgnored)
        self.tableWidget_2.setAutoScroll(True)
        self.tableWidget_2.setAutoScrollMargin(16)
        self.tableWidget_2.setAlternatingRowColors(False)
        self.tableWidget_2.setSelectionMode(QAbstractItemView.NoSelection)
        self.tableWidget_2.setShowGrid(True)
        self.tableWidget_2.setGridStyle(Qt.SolidLine)
        self.tableWidget_2.horizontalHeader().setCascadingSectionResizes(False)
        self.tableWidget_2.horizontalHeader().setHighlightSections(False)
        self.tableWidget_2.horizontalHeader().setProperty("showSortIndicator", False)
        self.tableWidget_2.verticalHeader().setVisible(False)

        self.verticalLayout.addWidget(self.tableWidget_2)

        self.widget = QWidget(self.centralwidget)
        self.widget.setObjectName(u"widget")
        sizePolicy2 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Minimum)
        sizePolicy2.setHorizontalStretch(0)
        sizePolicy2.setVerticalStretch(0)
        sizePolicy2.setHeightForWidth(self.widget.sizePolicy().hasHeightForWidth())
        self.widget.setSizePolicy(sizePolicy2)
        self.horizontalLayout = QHBoxLayout(self.widget)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.label_3 = QLabel(self.widget)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setFont(font1)

        self.horizontalLayout.addWidget(self.label_3)

        self.label_2 = QLabel(self.widget)
        self.label_2.setObjectName(u"label_2")
        sizePolicy3 = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Preferred)
        sizePolicy3.setHorizontalStretch(0)
        sizePolicy3.setVerticalStretch(0)
        sizePolicy3.setHeightForWidth(self.label_2.sizePolicy().hasHeightForWidth())
        self.label_2.setSizePolicy(sizePolicy3)
        self.label_2.setFrameShape(QFrame.StyledPanel)

        self.horizontalLayout.addWidget(self.label_2)

        self.pushButton_5 = QPushButton(self.widget)
        self.pushButton_5.setObjectName(u"pushButton_5")
        sizePolicy4 = QSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        sizePolicy4.setHorizontalStretch(0)
        sizePolicy4.setVerticalStretch(0)
        sizePolicy4.setHeightForWidth(self.pushButton_5.sizePolicy().hasHeightForWidth())
        self.pushButton_5.setSizePolicy(sizePolicy4)
        self.pushButton_5.setFont(font1)
        icon1 = QIcon()
        icon1.addFile(u"../../electric/\u4e00\u952e\u540c\u6b65.png", QSize(), QIcon.Normal, QIcon.Off)
        self.pushButton_5.setIcon(icon1)
        self.pushButton_5.setIconSize(QSize(26, 26))

        self.horizontalLayout.addWidget(self.pushButton_5)

        self.pushButton = QPushButton(self.widget)
        self.pushButton.setObjectName(u"pushButton")
        icon2 = QIcon()
        icon2.addFile(u":/pic/EXEL.png", QSize(), QIcon.Normal, QIcon.Off)
        self.pushButton.setIcon(icon2)
        self.pushButton.setIconSize(QSize(26, 26))

        self.horizontalLayout.addWidget(self.pushButton)

        self.debugButton = QPushButton(self.widget)
        self.debugButton.setObjectName(u"debugButton")

        self.horizontalLayout.addWidget(self.debugButton)


        self.verticalLayout.addWidget(self.widget)

        self.widget_2 = QWidget(self.centralwidget)
        self.widget_2.setObjectName(u"widget_2")
        sizePolicy2.setHeightForWidth(self.widget_2.sizePolicy().hasHeightForWidth())
        self.widget_2.setSizePolicy(sizePolicy2)
        self.horizontalLayout_2 = QHBoxLayout(self.widget_2)
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.serialPort_comboBox = QComboBox(self.widget_2)
        self.serialPort_comboBox.setObjectName(u"serialPort_comboBox")

        self.horizontalLayout_2.addWidget(self.serialPort_comboBox)

        self.pushButton_2 = QPushButton(self.widget_2)
        self.pushButton_2.setObjectName(u"pushButton_2")

        self.horizontalLayout_2.addWidget(self.pushButton_2)


        self.verticalLayout.addWidget(self.widget_2)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 726, 22))
        MainWindow.setMenuBar(self.menubar)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        ___qtablewidgetitem = self.tableWidget.horizontalHeaderItem(0)
        ___qtablewidgetitem.setText(QCoreApplication.translate("MainWindow", u"\u65b0\u5efa\u5217", None));
        ___qtablewidgetitem1 = self.tableWidget.horizontalHeaderItem(1)
        ___qtablewidgetitem1.setText(QCoreApplication.translate("MainWindow", u"\u65b0\u5efa\u5217", None));
        ___qtablewidgetitem2 = self.tableWidget.horizontalHeaderItem(2)
        ___qtablewidgetitem2.setText(QCoreApplication.translate("MainWindow", u"\u65b0\u5efa\u5217", None));
        ___qtablewidgetitem3 = self.tableWidget.horizontalHeaderItem(3)
        ___qtablewidgetitem3.setText(QCoreApplication.translate("MainWindow", u"\u65b0\u5efa\u5217", None));
        ___qtablewidgetitem4 = self.tableWidget.verticalHeaderItem(0)
        ___qtablewidgetitem4.setText(QCoreApplication.translate("MainWindow", u"\u65b0\u5efa\u884c", None));
        ___qtablewidgetitem5 = self.tableWidget.verticalHeaderItem(1)
        ___qtablewidgetitem5.setText(QCoreApplication.translate("MainWindow", u"\u65b0\u5efa\u884c", None));
        ___qtablewidgetitem6 = self.tableWidget.verticalHeaderItem(2)
        ___qtablewidgetitem6.setText(QCoreApplication.translate("MainWindow", u"\u65b0\u5efa\u884c", None));
        ___qtablewidgetitem7 = self.tableWidget.verticalHeaderItem(3)
        ___qtablewidgetitem7.setText(QCoreApplication.translate("MainWindow", u"\u65b0\u5efa\u884c", None));
        ___qtablewidgetitem8 = self.tableWidget.verticalHeaderItem(4)
        ___qtablewidgetitem8.setText(QCoreApplication.translate("MainWindow", u"\u65b0\u5efa\u884c", None));
        ___qtablewidgetitem9 = self.tableWidget.verticalHeaderItem(5)
        ___qtablewidgetitem9.setText(QCoreApplication.translate("MainWindow", u"\u65b0\u5efa\u884c", None));

        __sortingEnabled = self.tableWidget.isSortingEnabled()
        self.tableWidget.setSortingEnabled(False)
        ___qtablewidgetitem10 = self.tableWidget.item(0, 0)
        ___qtablewidgetitem10.setText(QCoreApplication.translate("MainWindow", u"\u8868\u53f7", None));
        ___qtablewidgetitem11 = self.tableWidget.item(0, 2)
        ___qtablewidgetitem11.setText(QCoreApplication.translate("MainWindow", u"\u989d\u5b9a\u7535\u538b", None));
        ___qtablewidgetitem12 = self.tableWidget.item(1, 0)
        ___qtablewidgetitem12.setText(QCoreApplication.translate("MainWindow", u"\u901a\u4fe1\u89c4\u7ea6", None));
        ___qtablewidgetitem13 = self.tableWidget.item(1, 2)
        ___qtablewidgetitem13.setText(QCoreApplication.translate("MainWindow", u"\u989d\u5b9a\u7535\u6d41", None));
        ___qtablewidgetitem14 = self.tableWidget.item(2, 0)
        ___qtablewidgetitem14.setText(QCoreApplication.translate("MainWindow", u"\u6ce2\u7279\u7387", None));
        ___qtablewidgetitem15 = self.tableWidget.item(2, 2)
        ___qtablewidgetitem15.setText(QCoreApplication.translate("MainWindow", u"\u6709\u529f\u5e38\u6570", None));
        ___qtablewidgetitem16 = self.tableWidget.item(3, 0)
        ___qtablewidgetitem16.setText(QCoreApplication.translate("MainWindow", u"\u901a\u4fe1\u5730\u5740", None));
        ___qtablewidgetitem17 = self.tableWidget.item(3, 2)
        ___qtablewidgetitem17.setText(QCoreApplication.translate("MainWindow", u"\u6709\u529f\u7b49\u7ea7", None));
        ___qtablewidgetitem18 = self.tableWidget.item(4, 0)
        ___qtablewidgetitem18.setText(QCoreApplication.translate("MainWindow", u"\u8868\u65f6\u95f4", None));
        ___qtablewidgetitem19 = self.tableWidget.item(4, 2)
        ___qtablewidgetitem19.setText(QCoreApplication.translate("MainWindow", u"\u65e0\u529f\u5e38\u6570", None));
        ___qtablewidgetitem20 = self.tableWidget.item(4, 3)
        ___qtablewidgetitem20.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        ___qtablewidgetitem21 = self.tableWidget.item(5, 2)
        ___qtablewidgetitem21.setText(QCoreApplication.translate("MainWindow", u"\u65e0\u529f\u7b49\u7ea7", None));
        ___qtablewidgetitem22 = self.tableWidget.item(5, 3)
        ___qtablewidgetitem22.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        self.tableWidget.setSortingEnabled(__sortingEnabled)

        ___qtablewidgetitem23 = self.tableWidget_2.horizontalHeaderItem(0)
        ___qtablewidgetitem23.setText(QCoreApplication.translate("MainWindow", u"\u8d39\u7387\u79cd\u7c7b", None));
        ___qtablewidgetitem24 = self.tableWidget_2.horizontalHeaderItem(1)
        ___qtablewidgetitem24.setText(QCoreApplication.translate("MainWindow", u"\u6b63\u5411\u6709\u529f\n"
"[kWh]", None));
        ___qtablewidgetitem25 = self.tableWidget_2.horizontalHeaderItem(2)
        ___qtablewidgetitem25.setText(QCoreApplication.translate("MainWindow", u"\u6b63\u5411\u65e0\u529f\n"
"[kvarh]", None));
        ___qtablewidgetitem26 = self.tableWidget_2.horizontalHeaderItem(3)
        ___qtablewidgetitem26.setText(QCoreApplication.translate("MainWindow", u"\u53cd\u5411\u6709\u529f\n"
"[kWh]", None));
        ___qtablewidgetitem27 = self.tableWidget_2.horizontalHeaderItem(4)
        ___qtablewidgetitem27.setText(QCoreApplication.translate("MainWindow", u"\u53cd\u5411\u65e0\u529f\n"
"[kvarh]", None));

        __sortingEnabled1 = self.tableWidget_2.isSortingEnabled()
        self.tableWidget_2.setSortingEnabled(False)
        ___qtablewidgetitem28 = self.tableWidget_2.item(0, 0)
        ___qtablewidgetitem28.setText(QCoreApplication.translate("MainWindow", u"\u603b", None));
        ___qtablewidgetitem29 = self.tableWidget_2.item(0, 2)
        ___qtablewidgetitem29.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        ___qtablewidgetitem30 = self.tableWidget_2.item(0, 4)
        ___qtablewidgetitem30.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        ___qtablewidgetitem31 = self.tableWidget_2.item(1, 0)
        ___qtablewidgetitem31.setText(QCoreApplication.translate("MainWindow", u"\u5c16", None));
        ___qtablewidgetitem32 = self.tableWidget_2.item(1, 2)
        ___qtablewidgetitem32.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        ___qtablewidgetitem33 = self.tableWidget_2.item(1, 4)
        ___qtablewidgetitem33.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        ___qtablewidgetitem34 = self.tableWidget_2.item(2, 0)
        ___qtablewidgetitem34.setText(QCoreApplication.translate("MainWindow", u"\u5cf0", None));
        ___qtablewidgetitem35 = self.tableWidget_2.item(2, 2)
        ___qtablewidgetitem35.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        ___qtablewidgetitem36 = self.tableWidget_2.item(2, 4)
        ___qtablewidgetitem36.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        ___qtablewidgetitem37 = self.tableWidget_2.item(3, 0)
        ___qtablewidgetitem37.setText(QCoreApplication.translate("MainWindow", u"\u5e73", None));
        ___qtablewidgetitem38 = self.tableWidget_2.item(3, 2)
        ___qtablewidgetitem38.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        ___qtablewidgetitem39 = self.tableWidget_2.item(3, 4)
        ___qtablewidgetitem39.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        ___qtablewidgetitem40 = self.tableWidget_2.item(4, 0)
        ___qtablewidgetitem40.setText(QCoreApplication.translate("MainWindow", u"\u8c37", None));
        ___qtablewidgetitem41 = self.tableWidget_2.item(4, 2)
        ___qtablewidgetitem41.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        ___qtablewidgetitem42 = self.tableWidget_2.item(4, 4)
        ___qtablewidgetitem42.setText(QCoreApplication.translate("MainWindow", u"\\", None));
        self.tableWidget_2.setSortingEnabled(__sortingEnabled1)

        self.label_3.setText(QCoreApplication.translate("MainWindow", u"\u8bfb\u8868\u6210\u529f", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"\u5982\u9700\u9009\u62e9\u7279\u5b9a\u65f6\u95f4\u6bb5\u8bfb\u53d6\uff0c\u8bf7\u5728\u6b64\u8f93\u5165\u65f6\u95f4", None))
        self.pushButton_5.setText("")
        self.pushButton.setText(QCoreApplication.translate("MainWindow", u"\u5bfc\u51fa\u5230exel", None))
        self.debugButton.setText(QCoreApplication.translate("MainWindow", u"debug", None))
        self.pushButton_2.setText(QCoreApplication.translate("MainWindow", u"\u8fde\u63a5", None))
    # retranslateUi

