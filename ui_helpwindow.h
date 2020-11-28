/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QWidget *centralwidget;
    QPushButton *back;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_pic;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *telegram;
    QPushButton *viber;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName(QStringLiteral("HelpWindow"));
        HelpWindow->resize(877, 641);
        HelpWindow->setStyleSheet(QLatin1String("background-color: #1B5EA6;\n"
"color:#fff;\n"
"font-size:16px;"));
        centralwidget = new QWidget(HelpWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        back = new QPushButton(centralwidget);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(70, 510, 121, 41));
        back->setStyleSheet(QLatin1String("#back {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#back:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 50, 431, 31));
        label->setStyleSheet(QStringLiteral("font-size:21px;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 100, 631, 51));
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(620, 180, 191, 161));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 200, 171, 16));
        label_3->setStyleSheet(QStringLiteral("font-weight:700;"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 198, 241, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 260, 181, 16));
        label_5->setStyleSheet(QStringLiteral("font-weight:700;"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 270, 221, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 290, 191, 16));
        label_7->setStyleSheet(QStringLiteral("font-weight:700;"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(70, 360, 311, 31));
        telegram = new QPushButton(centralwidget);
        telegram->setObjectName(QStringLiteral("telegram"));
        telegram->setGeometry(QRect(70, 400, 81, 31));
        telegram->setStyleSheet(QLatin1String("#telegram {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#telegram:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        viber = new QPushButton(centralwidget);
        viber->setObjectName(QStringLiteral("viber"));
        viber->setGeometry(QRect(180, 400, 81, 31));
        viber->setStyleSheet(QLatin1String("#viber {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#viber:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        HelpWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HelpWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 877, 27));
        HelpWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(HelpWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        HelpWindow->setStatusBar(statusbar);

        retranslateUi(HelpWindow);

        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HelpWindow)
    {
        HelpWindow->setWindowTitle(QApplication::translate("HelpWindow", "MainWindow", Q_NULLPTR));
        back->setText(QApplication::translate("HelpWindow", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        label->setText(QApplication::translate("HelpWindow", "\320\224\320\276\320\277\320\276\320\274\320\276\320\263\320\260 \321\211\320\276\320\264\320\276 \320\262\320\270\320\272\320\276\321\200\320\270\321\201\321\202\320\260\320\275\320\275\321\217 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\270", Q_NULLPTR));
        label_2->setText(QApplication::translate("HelpWindow", "\320\257\320\272\321\211\320\276 \321\203 \320\262\320\260\321\201 \320\262\320\270\320\275\320\270\320\272\320\273\320\270 \320\277\321\200\320\276\320\261\320\273\320\265\320\274\320\260 \320\277\321\200\320\270 \321\200\320\276\320\261\320\276\321\202\321\226 \320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\276\321\216, \321\202\320\276 \320\262\320\270 \320\274\320\276\320\266\320\265\321\202\320\265<br> \320\267\320\262\320\265\321\200\320\275\321\203\321\202\320\270\321\201\321\217 \320\262 \321\201\320\273\321\203\320\266\320\261\321\203 \320\277\321\226\320\264\321\202\321\200\320\270\320\274\320\272\320\270.\n"
"", Q_NULLPTR));
        label_pic->setText(QString());
        label_3->setText(QApplication::translate("HelpWindow", "admiralbub@ukr.net", Q_NULLPTR));
        label_4->setText(QApplication::translate("HelpWindow", "-  Email \321\201\320\273\321\203\320\266\320\261\320\270 \320\277\321\226\320\264\321\202\321\200\320\270\320\274\320\272\320\270", Q_NULLPTR));
        label_5->setText(QApplication::translate("HelpWindow", "+380 (087) 122-22-22", Q_NULLPTR));
        label_6->setText(QApplication::translate("HelpWindow", "- \320\242\320\265\320\273\320\265\321\204\320\276\320\275  \321\201\320\273\321\203\320\266\320\261\320\270 \320\277\321\226\320\264\321\202\321\200\320\270\320\274\320\272\320\270", Q_NULLPTR));
        label_7->setText(QApplication::translate("HelpWindow", "+380 (017) 132-42-52", Q_NULLPTR));
        label_8->setText(QApplication::translate("HelpWindow", "\320\234\320\265\321\201\320\265\320\275\320\264\320\266\320\265\321\200\320\270 \320\264\320\273\321\217 \320\267\320\262'\321\217\320\267\320\272\321\203 \320\267 \321\202\320\265\321\205\320\277\321\226\320\264\321\202\321\200\320\270\320\274\320\272\320\276\321\216:", Q_NULLPTR));
        telegram->setText(QApplication::translate("HelpWindow", "Telegram", Q_NULLPTR));
        viber->setText(QApplication::translate("HelpWindow", "Viber", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
