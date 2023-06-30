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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QSplitter *splitter;
    QProgressBar *progressBar;
    QProgressBar *progressBar_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(986, 558);
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
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(370, 220, 91, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "UART Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
