#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    // Инициализируем второе окно
    sWindow = new AboutWindow();
    // подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(sWindow, &AboutWindow::firstWindow, this, &MainWindow::show);


    // Инициализируем третье окно
    thirdWindow = new HelpWindow();
    // подключаем к слоту запуска главного окна по кнопке в третьем окне
    connect(thirdWindow, &HelpWindow::firstWindow, this, &MainWindow::show);

    // Инициализируем третье окно
    lestWindow = new TestWindow();
    // подключаем к слоту запуска главного окна по кнопке в третьем окне
    connect(lestWindow, &TestWindow::firstWindow, this, &MainWindow::show);

    QPixmap pix(":/resources/image/header-object.png");
    ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));



    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/resources/sounds/Original Tetris theme (Tetris Soundtrack).mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
     MainWindow ::close();
}

void MainWindow::on_pushButton_clicked()
{
    lestWindow->show();  // Показываем  окно о авторе
    this->close();    // Закрываем основное окно
}

void MainWindow::on_pushButton_3_clicked()
{
    sWindow->show();  // Показываем  окно о авторе
    this->close();    // Закрываем основное окно
}

void MainWindow::on_pushButton_2_clicked()
{
    thirdWindow->show();  // Показываем  окно о помощье
    this->close();    // Закрываем основное окно
}
