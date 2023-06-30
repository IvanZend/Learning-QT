/********************************************************************************
** Form generated from reading UI file 'dialog_0.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_0_H
#define UI_DIALOG_0_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *comboBox;
    QComboBox *comboBox_4;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QPushButton *pushButton_4;
    QComboBox *comboBox_3;
    QComboBox *comboBox_5;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QLabel *label_6;
    QComboBox *comboBox_6;
    QPushButton *pushButton;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    QLabel *label_8;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(1140, 593);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(210, 430, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 60, 49, 16));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(190, 60, 69, 22));
        comboBox_4 = new QComboBox(Dialog);
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(190, 150, 69, 22));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(110, 180, 49, 16));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(110, 280, 75, 24));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(110, 240, 49, 16));
        pushButton_4 = new QPushButton(Dialog);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(150, 310, 81, 24));
        comboBox_3 = new QComboBox(Dialog);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(190, 120, 69, 22));
        comboBox_5 = new QComboBox(Dialog);
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(190, 180, 69, 22));
        pushButton_5 = new QPushButton(Dialog);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(610, 30, 75, 24));
        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(210, 280, 75, 24));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(110, 210, 81, 16));
        comboBox_6 = new QComboBox(Dialog);
        comboBox_6->setObjectName("comboBox_6");
        comboBox_6->setGeometry(QRect(190, 210, 141, 22));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(620, 270, 75, 24));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(110, 150, 49, 16));
        comboBox_2 = new QComboBox(Dialog);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(190, 90, 69, 22));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 90, 61, 16));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 120, 61, 16));
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(340, 270, 261, 22));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(210, 240, 71, 22));
        textBrowser = new QTextBrowser(Dialog);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(340, 60, 351, 192));
        label_8 = new QLabel(Dialog);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(120, 450, 49, 16));
        label_8->setLineWidth(1);
        label_8->setTextFormat(Qt::AutoText);
        label_8->setScaledContents(false);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Port", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "Parity", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "Connect", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "Code", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dialog", "Refresh Ports", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Dialog", "Clear", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dialog", "Disconnect", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "Flow Control", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Send", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Stop Bits", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Baud Rate", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Data Bits", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_0_H
