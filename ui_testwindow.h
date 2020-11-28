/********************************************************************************
** Form generated from reading UI file 'testwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWINDOW_H
#define UI_TESTWINDOW_H

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

class Ui_TestWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_menu;
    QPushButton *answer_1;
    QLabel *label_heading;
    QLabel *label_score;
    QLabel *label_4;
    QPushButton *answer_2;
    QPushButton *answer_3;
    QPushButton *pushButton_first;
    QTextBrowser *question;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestWindow)
    {
        if (TestWindow->objectName().isEmpty())
            TestWindow->setObjectName(QStringLiteral("TestWindow"));
        TestWindow->resize(877, 641);
        TestWindow->setStyleSheet(QLatin1String("background-color: #1B5EA6;\n"
"color:#fff;"));
        centralwidget = new QWidget(TestWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_menu = new QPushButton(centralwidget);
        pushButton_menu->setObjectName(QStringLiteral("pushButton_menu"));
        pushButton_menu->setGeometry(QRect(50, 550, 111, 41));
        pushButton_menu->setStyleSheet(QLatin1String("#pushButton_menu {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#pushButton_menu:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        answer_1 = new QPushButton(centralwidget);
        answer_1->setObjectName(QStringLiteral("answer_1"));
        answer_1->setGeometry(QRect(60, 330, 71, 41));
        answer_1->setStyleSheet(QLatin1String("#answer_1 {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#answer_1:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        label_heading = new QLabel(centralwidget);
        label_heading->setObjectName(QStringLiteral("label_heading"));
        label_heading->setGeometry(QRect(60, 110, 661, 21));
        label_heading->setStyleSheet(QLatin1String("font-size:21px;\n"
"font-weight:600;"));
        label_score = new QLabel(centralwidget);
        label_score->setObjectName(QStringLiteral("label_score"));
        label_score->setGeometry(QRect(60, 70, 141, 16));
        label_score->setStyleSheet(QLatin1String("font-size:15px;\n"
"font-weight:600;"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 290, 91, 16));
        label_4->setStyleSheet(QLatin1String("font-size:15px;\n"
"font-weight:600;"));
        answer_2 = new QPushButton(centralwidget);
        answer_2->setObjectName(QStringLiteral("answer_2"));
        answer_2->setGeometry(QRect(160, 330, 71, 41));
        answer_2->setStyleSheet(QLatin1String("#answer_2 {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#answer_2:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        answer_3 = new QPushButton(centralwidget);
        answer_3->setObjectName(QStringLiteral("answer_3"));
        answer_3->setGeometry(QRect(260, 330, 71, 41));
        answer_3->setStyleSheet(QLatin1String("#answer_3 {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#answer_3:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        pushButton_first = new QPushButton(centralwidget);
        pushButton_first->setObjectName(QStringLiteral("pushButton_first"));
        pushButton_first->setGeometry(QRect(640, 550, 171, 41));
        pushButton_first->setStyleSheet(QLatin1String("#pushButton_first {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#pushButton_first:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        question = new QTextBrowser(centralwidget);
        question->setObjectName(QStringLiteral("question"));
        question->setGeometry(QRect(60, 160, 761, 91));
        QFont font;
        font.setPointSize(15);
        question->setFont(font);
        TestWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 877, 21));
        TestWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TestWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestWindow->setStatusBar(statusbar);

        retranslateUi(TestWindow);

        QMetaObject::connectSlotsByName(TestWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TestWindow)
    {
        TestWindow->setWindowTitle(QApplication::translate("TestWindow", "MainWindow", Q_NULLPTR));
        pushButton_menu->setText(QApplication::translate("TestWindow", "\320\222 \320\274\320\265\320\275\321\216", Q_NULLPTR));
        answer_1->setText(QApplication::translate("TestWindow", "\320\242\320\260\320\272", Q_NULLPTR));
        label_heading->setText(QApplication::translate("TestWindow", "\320\222\320\270\320\267\320\275\320\260\321\207\321\202\320\265, \321\207\320\270 \321\201\321\202\320\276\321\201\321\203\321\224\321\202\321\214\321\201\321\217 \320\262\320\260\321\201 \321\206\320\265 \321\202\320\262\320\265\321\200\320\264\320\266\320\265\320\275\320\275\321\217:", Q_NULLPTR));
        label_score->setText(QApplication::translate("TestWindow", "\320\237\320\270\321\202\320\260\320\275\320\275\321\217 1 \320\267 12", Q_NULLPTR));
        label_4->setText(QApplication::translate("TestWindow", "\320\222\321\226\320\264\320\277\320\276\320\262\321\226\320\264\321\226:", Q_NULLPTR));
        answer_2->setText(QApplication::translate("TestWindow", "\320\235\321\226", Q_NULLPTR));
        answer_3->setText(QApplication::translate("TestWindow", "\320\235\320\265 \320\267\320\275\320\260\321\216", Q_NULLPTR));
        pushButton_first->setText(QApplication::translate("TestWindow", "\320\240\320\276\320\267\320\277\320\276\321\207\320\260\321\202\320\270 \321\201\320\277\320\276\321\207\320\260\321\202\320\272\321\203", Q_NULLPTR));
        question->setHtml(QApplication::translate("TestWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Lorem Ipsum - \321\215\321\202\320\276 \321\202\320\265\320\272\321\201\321\202-&quot;\321\200\321\213\320\261\320\260&quot;, \321\207\320\260\321\201\321\202\320\276 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\320\274\321\213\320\271 \320\262 \320\277\320\265\321\207\320\260\321\202\320\270 \320\270 \320\262\321\215\320\261-\320\264\320\270\320\267\320\260\320\271\320\275\320\265.<br />Lorem Ipsum \321\217\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \321\201\321\202\320\260\320\275\320"
                        "\264\320\260\321\200\321\202\320\275\320\276\320\271 &quot;\321\200\321\213\320\261\320\276\320\271&quot; \320\264\320\273\321\217 \321\202\320\265\320\272\321\201\321\202\320\276\320\262 \320\275\320\260 \320\273\320\260\321\202\320\270\320\275\320\270\321\206\320\265 \321\201 \320\275\320\260\321\207\320\260\320\273\320\260 XVI \320\262\320\265\320\272\320\260.</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestWindow: public Ui_TestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWINDOW_H
