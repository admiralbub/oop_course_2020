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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *start;
    QPushButton *help;
    QPushButton *about;
    QPushButton *exit;
    QLabel *label_heading;
    QLabel *label_pic;
    QLabel *label_footer;
    QPushButton *button_mus;
    QPushButton *button_nomus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(877, 641);
        MainWindow->setStyleSheet(QLatin1String("QWidget {\n"
"   background: linear-gradient(-45deg,#6193e1,#1B5EA6,#6193e1),#1B5EA6;\n"
"   color:#fff;\n"
"   cursor:pointer;\n"
"}\n"
"QPushButton {\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	 background-color: #fff; \n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        start = new QPushButton(centralwidget);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(150, 240, 571, 51));
        start->setStyleSheet(QLatin1String("#start {\n"
"   color:#000; \n"
"   border-radius:20px;\n"
"   font-weight:400;\n"
"   background:#FFD200;\n"
"   font-size:15px;\n"
"   cursor:pointer;\n"
"}\n"
"#start:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"     margin-right:12px;\n"
"	 margin-left:12px;\n"
"}"));
        help = new QPushButton(centralwidget);
        help->setObjectName(QStringLiteral("help"));
        help->setGeometry(QRect(150, 320, 571, 51));
        help->setStyleSheet(QLatin1String("#help {\n"
"   color:#000; \n"
"   border-radius:20px;\n"
"   background:#FFD200;\n"
"   font-size:15px;\n"
"   cursor:pointer;\n"
"}\n"
"#help:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"	 margin-right:12px;\n"
"	 margin-left:12px;\n"
"}"));
        about = new QPushButton(centralwidget);
        about->setObjectName(QStringLiteral("about"));
        about->setGeometry(QRect(150, 400, 571, 51));
        about->setStyleSheet(QLatin1String("#about {\n"
"   color:#000; \n"
"   border-radius:20px;\n"
"   background:#FFD200;\n"
"   font-size:15px;\n"
"   cursor:pointer;\n"
"}\n"
"#about:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"     margin-right:12px;\n"
"	 margin-left:12px;\n"
"}"));
        exit = new QPushButton(centralwidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(150, 480, 571, 51));
        exit->setStyleSheet(QLatin1String("#exit {\n"
"   color:#000; \n"
"   border-radius:20px;\n"
"   background:#FFD200;\n"
"   font-size:15px;\n"
"   cursor:pointer;\n"
"}\n"
"#exit:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"     margin-right:12px;\n"
"	 margin-left:12px;\n"
"}"));
        label_heading = new QLabel(centralwidget);
        label_heading->setObjectName(QStringLiteral("label_heading"));
        label_heading->setGeometry(QRect(120, 160, 621, 51));
        label_heading->setLayoutDirection(Qt::LeftToRight);
        label_heading->setStyleSheet(QLatin1String("font-size:17px;\n"
"text-align:center;\n"
"font-weight:500;"));
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(390, 40, 111, 101));
        label_footer = new QLabel(centralwidget);
        label_footer->setObjectName(QStringLiteral("label_footer"));
        label_footer->setGeometry(QRect(330, 560, 221, 20));
        button_mus = new QPushButton(centralwidget);
        button_mus->setObjectName(QStringLiteral("button_mus"));
        button_mus->setGeometry(QRect(790, 540, 51, 41));
        button_mus->setStyleSheet(QLatin1String("#button_mus {\n"
"   color:#000; \n"
"   font-weight:400;\n"
"   background:#FFD200;\n"
"   border-radius:10px;\n"
"   font-size:15px;\n"
"   cursor:pointer;\n"
"}\n"
"#button_mus:hover {\n"
"	 background:#fff;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/image/sound on.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_mus->setIcon(icon);
        button_mus->setIconSize(QSize(32, 32));
        button_nomus = new QPushButton(centralwidget);
        button_nomus->setObjectName(QStringLiteral("button_nomus"));
        button_nomus->setGeometry(QRect(790, 540, 51, 41));
        button_nomus->setStyleSheet(QLatin1String("#button_nomus {\n"
"   color:#000; \n"
"   font-weight:400;\n"
"   background:#FFD200;\n"
"   border-radius:10px;\n"
"   font-size:15px;\n"
"   cursor:pointer;\n"
"}\n"
"#button_nomus:hover {\n"
"	 background:#fff;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resources/image/sound off.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_nomus->setIcon(icon1);
        button_nomus->setIconSize(QSize(32, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 877, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        start->setText(QApplication::translate("MainWindow", "\320\240\320\276\320\267\320\277\320\276\321\207\320\260\321\202\320\270 \320\276\320\277\320\270\321\202\321\203\320\262\320\260\320\275\320\275\321\217", Q_NULLPTR));
        help->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\277\320\276\320\274\320\276\320\263\320\260", Q_NULLPTR));
        about->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\321\203", Q_NULLPTR));
        exit->setText(QApplication::translate("MainWindow", "\320\222\320\270\321\205\321\226\320\264", Q_NULLPTR));
        label_heading->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:13pt;\">\320\227\320\260\321\201\321\202\320\276\321\201\321\203\320\275\320\276\320\272 \320\264\320\273\321\217 \320\262\320\270\320\261\320\276\321\200\321\203 </span></p><p align=\"center\"><span style=\" font-size:13pt;\">\321\201\320\277\320\265\321\206\321\226\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\226 \320\264\320\273\321\217 \320\275\320\260\320\262\321\207\320\260\320\275\320\275\321\217 \320\262 \320\235\320\243 &quot;\320\227\320\260\320\277\320\276\321\200\321\226\320\267\321\214\320\272\320\260 \320\277\320\276\320\273\321\226\321\202\320\265\321\205\320\275\321\226\320\272\320\260&quot;</span></p></body></html>", Q_NULLPTR));
        label_pic->setText(QString());
        label_footer->setText(QApplication::translate("MainWindow", "   \302\251 \320\232\320\235\320\242-139  \320\235\320\243 \"\320\227\320\260\320\277\320\276\321\200\321\226\320\267\321\214\320\272\320\260 \320\277\320\276\320\273\321\226\321\202\320\265\321\205\320\275\321\226\320\272\320\260\"", Q_NULLPTR));
        button_mus->setText(QString());
        button_nomus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
