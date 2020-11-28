/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

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

class Ui_AboutWindow
{
public:
    QWidget *centralwidget;
    QPushButton *back;
    QLabel *label_heading;
    QLabel *label_image;
    QTextBrowser *text_info;
    QLabel *text_author;
    QLabel *author_1;
    QLabel *author_2;
    QLabel *author_3;
    QLabel *author_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QStringLiteral("AboutWindow"));
        AboutWindow->resize(877, 641);
        AboutWindow->setStyleSheet(QLatin1String("background-color: #1B5EA6;\n"
"color:#fff;"));
        centralwidget = new QWidget(AboutWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        back = new QPushButton(centralwidget);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(50, 510, 101, 41));
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
        label_heading = new QLabel(centralwidget);
        label_heading->setObjectName(QStringLiteral("label_heading"));
        label_heading->setGeometry(QRect(40, 50, 361, 31));
        label_heading->setStyleSheet(QStringLiteral("font-size:21px;"));
        label_image = new QLabel(centralwidget);
        label_image->setObjectName(QStringLiteral("label_image"));
        label_image->setGeometry(QRect(530, 80, 271, 231));
        text_info = new QTextBrowser(centralwidget);
        text_info->setObjectName(QStringLiteral("text_info"));
        text_info->setGeometry(QRect(40, 110, 401, 151));
        text_author = new QLabel(centralwidget);
        text_author->setObjectName(QStringLiteral("text_author"));
        text_author->setGeometry(QRect(50, 300, 151, 16));
        text_author->setStyleSheet(QLatin1String("font-size:15px;\n"
"font-weight:600;"));
        author_1 = new QLabel(centralwidget);
        author_1->setObjectName(QStringLiteral("author_1"));
        author_1->setGeometry(QRect(50, 340, 421, 16));
        author_1->setStyleSheet(QLatin1String("font-size:14px;\n"
""));
        author_2 = new QLabel(centralwidget);
        author_2->setObjectName(QStringLiteral("author_2"));
        author_2->setGeometry(QRect(50, 370, 431, 16));
        author_2->setStyleSheet(QStringLiteral("font-size:14px;"));
        author_3 = new QLabel(centralwidget);
        author_3->setObjectName(QStringLiteral("author_3"));
        author_3->setGeometry(QRect(50, 400, 441, 16));
        author_3->setStyleSheet(QStringLiteral("font-size:14px;"));
        author_4 = new QLabel(centralwidget);
        author_4->setObjectName(QStringLiteral("author_4"));
        author_4->setGeometry(QRect(50, 430, 441, 16));
        author_4->setStyleSheet(QStringLiteral("font-size:14px;"));
        AboutWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AboutWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 877, 21));
        AboutWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AboutWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AboutWindow->setStatusBar(statusbar);

        retranslateUi(AboutWindow);

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AboutWindow)
    {
        AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "MainWindow", Q_NULLPTR));
        back->setText(QApplication::translate("AboutWindow", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        label_heading->setText(QApplication::translate("AboutWindow", "\320\206\320\275\321\204\320\276\321\200\320\274\320\260\321\206\321\226\321\217 \320\277\321\200\320\276 \321\200\320\276\320\267\321\200\320\276\320\261\320\275\320\270\320\272\321\226\320\262 ", Q_NULLPTR));
        label_image->setText(QString());
        text_info->setHtml(QApplication::translate("AboutWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Lorem Ipsum - \321\215\321\202\320\276 \321\202\320\265\320\272\321\201\321\202- &quot;\321\200\321\213\320\261\320\260&quot;, \321\207\320\260\321\201\321\202\320\276 \320\230\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\320\274\321\213\320\271 \320\262 \320\277\320\265\321\207\320\260\321\202\320\270 \320\270 \320\262\321\215\320\261-\320\264\320\270\320\267\320\260\320\271\320\275\320\265. Lorem Ipsum \321\217\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \321\201\321\202\320\260\320\275\320"
                        "\264\320\260\321\200\321\202\320\275\320\276\320\271 &quot;\321\200\321\213\320\261\320\276\320\271&quot; \320\264\320\273\321\217 \321\202\320\265\320\272\321\201\321\202\320\276\320\262 \320\275\320\260 \320\273\320\260\321\202\320\270\320\275\320\270\321\206\320\265 \321\201 \320\275\320\260\321\207\320\260\320\273\320\260 XVI \320\262\320\265\320\272\320\260. \320\222 \321\202\320\276 \320\262\321\200\320\265\320\274\321\217 \320\275\320\265\320\272\320\270\320\271 \320\261\320\265\320\267\321\213\320\274\321\217\320\275\320\275\321\213\320\271 \320\277\320\265\321\207\320\260\321\202\320\275\320\270\320\272 \321\201\320\276\320\267\320\264\320\260\320\273 \320\261\320\276\320\273\321\214\321\210\321\203\321\216 \320\272\320\276\320\273\320\273\320\265\320\272\321\206\320\270\321\216 \321\200\320\260\320\267\320\274\320\265\321\200\320\276\320\262 \320\270 \321\204\320\276\321\200\320\274 \321\210\321\200\320\270\321\204\321\202\320\276\320\262, \320\230\321\201\320\277\320\276\320\273\321\214\320\267\321\203"
                        "\321\217 Lorem Ipsum \320\264\320\273\321\217 \321\200\320\260\321\201\320\277\320\265\321\207\320\260\321\202\320\272\320\270 \320\276\320\261\321\200\320\260\320\267\321\206\320\276\320\262. Lorem</span></p></body></html>", Q_NULLPTR));
        text_author->setText(QApplication::translate("AboutWindow", "\320\220\320\262\321\202\320\276\321\200\320\270 \320\267\320\260\321\201\321\202\320\276\321\201\321\203\320\275\320\272\321\203", Q_NULLPTR));
        author_1->setText(QApplication::translate("AboutWindow", "\320\224\320\270\320\272\320\260\321\200\321\214\320\276\320\262 \320\220\321\200\321\202\320\265\320\274 - \320\223\321\200\320\260\321\204\321\226\321\207\320\275\320\270\320\271 \321\226\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201", Q_NULLPTR));
        author_2->setText(QApplication::translate("AboutWindow", "\320\227\321\203\321\224\320\262 \320\221\320\276\320\263\320\264\320\260\320\275 - \320\240\320\276\320\261\320\276\321\202\320\260 \320\267 \320\264\320\260\320\275\320\270\320\274\320\270", Q_NULLPTR));
        author_3->setText(QApplication::translate("AboutWindow", "\320\224\320\276\320\273\320\266\320\265\320\275\320\272\320\276 \320\244\321\226\320\273\321\226\320\277\320\277 - \320\240\320\265\320\260\320\273\321\226\320\267\320\260\321\206\321\226\321\217 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\226\320\262", Q_NULLPTR));
        author_4->setText(QApplication::translate("AboutWindow", "\320\237\320\260\320\273\320\260\320\274\320\260\321\200\321\207\321\203\320\272 \320\220\321\200\321\202\320\265\320\274 - \320\236\320\261\321\200\320\276\320\261\320\272\320\260 \320\262\320\270\320\275\321\217\321\202\320\272\320\276\320\262\320\270\321\205 \321\201\320\270\321\202\321\203\320\260\321\206\321\226\320\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
