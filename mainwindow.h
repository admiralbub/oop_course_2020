#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <aboutwindow.h>
#include <helpwindow.h>
#include <testwindow.h>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "resultwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void resultwindow();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_button_mus_clicked();



    void on_button_nomus_clicked();

private:
    Ui::MainWindow *ui;
    AboutWindow *sWindow;
    HelpWindow *thirdWindow;
    TestWindow *lestWindow;

};
#endif // MAINWINDOW_H
