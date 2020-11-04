#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);


    // Инициализируем  окно о авторе
    sWindow = new AboutWindow();
    connect(sWindow, &AboutWindow::firstWindow, this, &MainWindow::show);

    // Инициализируем  окно о помощи
    thirdWindow = new HelpWindow();
    connect(thirdWindow, &HelpWindow::firstWindow, this, &MainWindow::show);

    // Инициализируем окно с тестами
    lestWindow = new TestWindow();
    connect(lestWindow, &TestWindow::firstWindow, this, &MainWindow::show);

    //Подгружаем основное лого ЗНТУ
    QPixmap pix(":/resources/image/header-object.png");
    ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

    //Добавляем фоновую музыку для теста
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/resources/sounds/Paul Mauriat - Love Is Blue.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
    ////////////////////////////////////////////////////////////////////////////
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_4_clicked()
{
     MainWindow ::close();  // Закрытие программы
}

void MainWindow::on_pushButton_clicked()
{
    lestWindow->show();  // Показываем  окно с тестами
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
