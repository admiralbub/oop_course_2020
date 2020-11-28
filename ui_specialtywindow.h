/********************************************************************************
** Form generated from reading UI file 'specialtywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECIALTYWINDOW_H
#define UI_SPECIALTYWINDOW_H

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

class Ui_SpecialtyWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *menu_button;
    QPushButton *site_nuzp;
    QLabel *label_5;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SpecialtyWindow)
    {
        if (SpecialtyWindow->objectName().isEmpty())
            SpecialtyWindow->setObjectName(QStringLiteral("SpecialtyWindow"));
        SpecialtyWindow->resize(877, 641);
        SpecialtyWindow->setStyleSheet(QLatin1String("background-color: #1B5EA6;\n"
"color:#fff;"));
        centralwidget = new QWidget(SpecialtyWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 60, 791, 51));
        label->setStyleSheet(QStringLiteral("font-size:21px;"));
        menu_button = new QPushButton(centralwidget);
        menu_button->setObjectName(QStringLiteral("menu_button"));
        menu_button->setGeometry(QRect(50, 550, 121, 41));
        menu_button->setStyleSheet(QLatin1String("#menu_button {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#menu_button:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        site_nuzp = new QPushButton(centralwidget);
        site_nuzp->setObjectName(QStringLiteral("site_nuzp"));
        site_nuzp->setGeometry(QRect(610, 550, 231, 41));
        site_nuzp->setStyleSheet(QLatin1String("#site_nuzp {\n"
"   color:#000;\n"
"   border-radius:5px;\n"
"   background:#FFD200;\n"
"   font-size:14px;\n"
"   cursor:pointer;\n"
"}\n"
"#site_nuzp:hover {\n"
"	 background:#fff;\n"
"     cursor:pointer;\n"
"}"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 140, 781, 16));
        label_5->setStyleSheet(QLatin1String("font-size:14px;\n"
"font-weight:600;"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(50, 190, 781, 311));
        textBrowser->setStyleSheet(QStringLiteral("color:#fff;"));
        SpecialtyWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SpecialtyWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 877, 21));
        SpecialtyWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SpecialtyWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SpecialtyWindow->setStatusBar(statusbar);

        retranslateUi(SpecialtyWindow);

        QMetaObject::connectSlotsByName(SpecialtyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SpecialtyWindow)
    {
        SpecialtyWindow->setWindowTitle(QApplication::translate("SpecialtyWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("SpecialtyWindow", "<html><head/><body><p>\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\277\320\276 \320\276\320\261\321\200\320\260\320\275\320\276\320\274\321\203 \320\275\320\260\320\277\321\200\321\217\320\274\320\272\321\203 \320\264\320\273\321\217 \320\275\320\260\320\262\321\207\320\260\320\275\320\275\321\217<br/>\320\262 \320\235\320\243 &quot;\320\227\320\260\320\277\320\276\321\200\321\226\320\267\321\214\320\272\320\260 \320\277\320\276\320\273\321\226\321\202\320\265\321\205\320\275\321\226\320\272\320\260&quot;</p></body></html>", Q_NULLPTR));
        menu_button->setText(QApplication::translate("SpecialtyWindow", "\320\222 \320\274\320\265\320\275\321\216", Q_NULLPTR));
        site_nuzp->setText(QApplication::translate("SpecialtyWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\264\320\276 \321\201\320\260\320\271\321\202\321\203 \320\235\320\243\320\227\320\237", Q_NULLPTR));
        label_5->setText(QApplication::translate("SpecialtyWindow", "\320\240\320\265\320\272\320\276\320\274\320\265\320\275\320\264\320\276\320\262\320\260\320\275\321\226 \321\201\320\277\320\265\321\206\321\226\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\226 :", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("SpecialtyWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lora','serif'; font-size:14pt; font-weight:600; color:#ffffff;\">053 \320\237\321\201\320\270\321\205\320\276\320\273\320\276\320\263\321\226\321\217</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lora','serif'; font-size:14pt; font-weight:600; color:#ffffff;\">054 \320\241\320\276\321\206\321\226\320\276\320\273\320\276\320\263\321\226\321\217</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; "
                        "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lora','serif'; font-size:14pt; font-weight:600; color:#ffffff;\">061 \320\226\321\203\321\200\320\275\320\260\320\273\321\226\321\201\321\202\320\270\320\272\320\260</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lora','serif'; font-size:14pt; font-weight:600; color:#ffffff;\">231 \320\241\320\276\321\206\321\226\320\260\320\273\321\214\320\275\320\260 \321\200\320\276\320\261\320\276\321\202\320\260</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lora','serif'; font-size:14pt; font-weight:600; color:#ffffff;\">053 \320\237\321\201\320\270\321\205\320\276\320\273\320\276\320\263\321\226\321\217</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; mar"
                        "gin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lora','serif'; font-size:14pt; font-weight:600; color:#ffffff;\">054 \320\241\320\276\321\206\321\226\320\276\320\273\320\276\320\263\321\226\321\217</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lora','serif'; font-size:14pt; font-weight:600; color:#ffffff;\">061 \320\226\321\203\321\200\320\275\320\260\320\273\321\226\321\201\321\202\320\270\320\272\320\260</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lora','serif'; font-size:14pt; font-weight:600; color:#ffffff;\">231 \320\241\320\276\321\206\321\226\320\260\320\273\321\214\320\275\320\260 \321\200\320\276\320\261\320\276\321\202\320\260</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px"
                        "; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SpecialtyWindow: public Ui_SpecialtyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECIALTYWINDOW_H
