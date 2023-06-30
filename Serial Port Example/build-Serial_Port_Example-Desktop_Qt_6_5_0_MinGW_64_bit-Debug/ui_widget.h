/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QPushButton *pushButton_5;
    QSplitter *splitter;
    QProgressBar *progressBar;
    QProgressBar *progressBar_5;
    QLabel *label_8;
    QPushButton *pushButton_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(986, 558);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 60, 49, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 90, 61, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(370, 120, 61, 16));
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(370, 150, 49, 16));
        label_5 = new QLabel(Widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(370, 180, 49, 16));
        label_6 = new QLabel(Widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(370, 210, 81, 16));
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(450, 60, 69, 22));
        comboBox_2 = new QComboBox(Widget);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(450, 90, 69, 22));
        comboBox_3 = new QComboBox(Widget);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(450, 120, 69, 22));
        comboBox_4 = new QComboBox(Widget);
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(450, 150, 69, 22));
        comboBox_5 = new QComboBox(Widget);
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(450, 180, 69, 22));
        comboBox_6 = new QComboBox(Widget);
        comboBox_6->setObjectName("comboBox_6");
        comboBox_6->setGeometry(QRect(450, 210, 141, 22));
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(600, 60, 351, 192));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(600, 270, 261, 22));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(880, 270, 75, 24));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(370, 280, 75, 24));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(470, 280, 75, 24));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(410, 310, 81, 24));
        label_7 = new QLabel(Widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(370, 240, 49, 16));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(470, 240, 71, 22));
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(870, 30, 75, 24));
        splitter = new QSplitter(Widget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(80, 100, 24, 124));
        splitter->setOrientation(Qt::Horizontal);
        progressBar = new QProgressBar(splitter);
        progressBar->setObjectName("progressBar");
        progressBar->setEnabled(true);
        progressBar->setValue(24);
        progressBar->setOrientation(Qt::Vertical);
        splitter->addWidget(progressBar);
        progressBar_5 = new QProgressBar(Widget);
        progressBar_5->setObjectName("progressBar_5");
        progressBar_5->setEnabled(true);
        progressBar_5->setGeometry(QRect(120, 100, 24, 124));
        progressBar_5->setValue(24);
        progressBar_5->setOrientation(Qt::Vertical);
        label_8 = new QLabel(Widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(150, 300, 49, 16));
        label_8->setLineWidth(1);
        label_8->setTextFormat(Qt::AutoText);
        label_8->setScaledContents(false);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(70, 30, 111, 24));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Port", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Baud Rate", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Data Bits", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Stop Bits", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Parity", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Flow Control", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Send", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "Connect", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "Disconnect", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "Refresh Ports", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "Code", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "Clear", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "0", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "UART Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
