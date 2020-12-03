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
    void mainwindow();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_button_mus_clicked();



    void on_button_nomus_clicked();

    void on_start_clicked();

    void on_help_clicked();

    void on_about_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
    AboutWindow *sWindow;
    HelpWindow *thirdWindow;
    TestWindow *testWindow;

};
#endif // MAINWINDOW_H
