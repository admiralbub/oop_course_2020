/********************************************************************************
** Form generated from reading UI file 'resultwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWINDOW_H
#define UI_RESULTWINDOW_H

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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_heading;
    QLabel *subtitle;
    QLabel *system_1;
    QLabel *system_2;
    QLabel *system_3;
    QLabel *system_4;
    QLabel *mark;
    QLabel *balls_1;
    QLabel *balls_2;
    QLabel *balls_3;
    QLabel *balls_4;
    QTextBrowser *system_info;
    QPushButton *first;
    QPushButton *direction;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ResultWindow)
    {
        if (ResultWindow->objectName().isEmpty())
            ResultWindow->setObjectName(QStringLiteral("ResultWindow"));
        ResultWindow->resize(877, 672);
        ResultWindow->setStyleSheet(QLatin1String("background-color: #1B5EA6;\n"
"color:#fff;"));
        centralwidget = new QWidget(ResultWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_heading = new QLabel(centralwidget);
        label_heading->setObjectName(QStringLiteral("label_heading"));
        label_heading->setGeometry(QRect(60, 60, 391, 21));
        label_heading->setStyleSheet(QStringLiteral("font-size:21px;"));
        subtitle = new QLabel(centralwidget);
        subtitle->setObjectName(QStringLiteral("subtitle"));
        subtitle->setGeometry(QRect(60, 110, 401, 16));
        system_1 = new QLabel(centralwidget);
        system_1->setObjectName(QStringLiteral("system_1"));
        system_1->setGeometry(QRect(70, 180, 321, 31));
        system_2 = new QLabel(centralwidget);
        system_2->setObjectName(QStringLiteral("system_2"));
        system_2->setGeometry(QRect(70, 230, 331, 31));
        system_3 = new QLabel(centralwidget);
        system_3->setObjectName(QStringLiteral("system_3"));
        system_3->setGeometry(QRect(70, 280, 341, 31));
        system_4 = new QLabel(centralwidget);
        system_4->setObjectName(QStringLiteral("system_4"));
        system_4->setGeometry(QRect(70, 330, 331, 31));
        mark = new QLabel(centralwidget);
        mark->setObjectName(QStringLiteral("mark"));
        mark->setGeometry(QRect(70, 390, 111, 16));
        balls_1 = new QLabel(centralwidget);
        balls_1->setObjectName(QStringLiteral("balls_1"));
        balls_1->setGeometry(QRect(430, 180, 91, 31));
        balls_1->setStyleSheet(QLatin1String("font-size:14px;\n"
"font-weight:700;\n"
"color:rgb(255, 170, 0);\n"
""));
        balls_2 = new QLabel(centralwidget);
        balls_2->setObjectName(QStringLiteral("balls_2"));
        balls_2->setGeometry(QRect(430, 230, 91, 31));
        balls_2->setStyleSheet(QLatin1String("font-size:14px;\n"
"font-weight:700;"));
        balls_3 = new QLabel(centralwidget);
        balls_3->setObjectName(QStringLiteral("balls_3"));
        balls_3->setGeometry(QRect(430, 280, 91, 31));
        balls_3->setStyleSheet(QLatin1String("font-size:14px;\n"
"font-weight:700;"));
        balls_4 = new QLabel(centralwidget);
        balls_4->setObjectName(QStringLiteral("balls_4"));
        balls_4->setGeometry(QRect(430, 330, 101, 31));
        balls_4->setStyleSheet(QLatin1String("font-size:14px;\n"
"font-weight:700;"));
        system_info = new QTextBrowser(centralwidget);
        system_info->setObjectName(QStringLiteral("system_info"));
        system_info->setGeometry(QRect(70, 420, 601, 121));
        first = new QPushButton(centralwidget);
        first->setObjectName(QStringLiteral("first"));
        first->setGeometry(QRect(70, 570, 111, 41));
        first->setStyleSheet(QLatin1String("#first {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#first:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        direction = new QPushButton(centralwidget);
        direction->setObjectName(QStringLiteral("direction"));
        direction->setGeometry(QRect(600, 570, 221, 41));
        direction->setStyleSheet(QLatin1String("#direction {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#direction:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        ResultWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ResultWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 877, 21));
        ResultWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ResultWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ResultWindow->setStatusBar(statusbar);

        retranslateUi(ResultWindow);

        QMetaObject::connectSlotsByName(ResultWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ResultWindow)
    {
        ResultWindow->setWindowTitle(QApplication::translate("ResultWindow", "MainWindow", Q_NULLPTR));
        label_heading->setText(QApplication::translate("ResultWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \321\202\320\265\321\201\321\202\321\203\320\262\320\260\320\275\320\275\321\217", Q_NULLPTR));
        subtitle->setText(QApplication::translate("ResultWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\320\222\320\270\320\274\320\276\320\263\320\270, \321\217\320\272\321\226 \320\262\320\270 \320\267\320\260\320\264\320\276\320\262\320\276\320\273\321\214\320\275\320\270\320\273\320\270:</span></p></body></html>", Q_NULLPTR));
        system_1->setText(QApplication::translate("ResultWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\240\320\276\320\261\320\276\321\202\320\260 \320\267 \320\273\321\216\320\264\321\214\320\274\320\270</span></p></body></html>", Q_NULLPTR));
        system_2->setText(QApplication::translate("ResultWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\240\320\276\320\261\320\276\321\202\320\260 \320\267 \321\202\320\265\321\205\320\275\321\226\320\272\320\276\321\216</span></p></body></html>", Q_NULLPTR));
        system_3->setText(QApplication::translate("ResultWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\242\320\262\320\276\321\200\321\207\320\260 \321\200\320\276\320\261\320\276\321\202\320\260</span></p></body></html>", Q_NULLPTR));
        system_4->setText(QApplication::translate("ResultWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\240\320\276\320\261\320\276\321\202\320\260 \320\267\321\226 \320\267\320\275\320\260\320\272\320\276\320\262\320\276\321\216 \321\201\320\270\321\201\321\202\320\265\320\274\320\276\321\216</span></p></body></html>", Q_NULLPTR));
        mark->setText(QApplication::translate("ResultWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\320\237\321\200\320\270\320\274\321\226\321\202\320\272\320\260</span></p></body></html>", Q_NULLPTR));
        balls_1->setText(QApplication::translate("ResultWindow", "<html><head/><body><p><span style=\" font-size:14pt; color:#FFA500;\">10%</span></p></body></html>", Q_NULLPTR));
        balls_2->setText(QApplication::translate("ResultWindow", "<html><head/><body><p><span style=\" font-size:14pt; color:#ffff00;\">50%</span></p></body></html>", Q_NULLPTR));
        balls_3->setText(QApplication::translate("ResultWindow", "<html><head/><body><p><span style=\" font-size:14pt; color:#ffff00;\">60%</span></p></body></html>", Q_NULLPTR));
        balls_4->setText(QApplication::translate("ResultWindow", "<html><head/><body><p><span style=\" font-size:14pt; color:#55ff00;\">100%</span></p></body></html>", Q_NULLPTR));
        system_info->setHtml(QApplication::translate("ResultWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\302\253\320\233\321\216\320\264\320\270\320\275\320\260 - \321\205\321\203\320\264\320\276\320\266\320\275\321\226\320\271 \320\276\320\261\321\200\320\260\320\267\302\273 - \321\206\320\265 \320\262\321\201\321\226 \321\202\320\262\320\276\321\200\321\207\321\226 \321\201\320\277\320\265\321\206\321\226\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\226.</span></p></body></html>", Q_NULLPTR));
        first->setText(QApplication::translate("ResultWindow", "\320\222 \320\274\320\265\320\275\321\216", Q_NULLPTR));
        direction->setText(QApplication::translate("ResultWindow", "\320\236\320\261\321\200\320\260\321\202\320\270 \320\275\320\260\320\277\321\200\321\217\320\274\320\276\320\272 \320\277\321\200\320\276\321\204\320\265\321\201\321\226\321\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ResultWindow: public Ui_ResultWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWINDOW_H
