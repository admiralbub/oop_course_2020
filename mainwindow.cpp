#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMediaPlayer>
#include "resultwindow.h"
#include "QDebug"

bool viz = true;
bool mus = true;
QMediaPlayer *music;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    setWindowTitle("Застосунок для вибору спеціальності для навчання в НУ «Запорізька політехніка»!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    setMinimumSize(877, 641);
    setMaximumSize(877, 641);

    // Инициализируем  окно о авторе
    sWindow = new AboutWindow();
    connect(sWindow, &AboutWindow::firstWindow, this, &MainWindow::show);

    // Инициализируем  окно о помощи
    thirdWindow = new HelpWindow();
    connect(thirdWindow, &HelpWindow::firstWindow, this, &MainWindow::show);

    // Инициализируем окно с тестами
    testWindow = new TestWindow();
    connect(testWindow, &TestWindow::firstWindow, this, &MainWindow::show);

    //Подгружаем основное лого ЗНТУ
    QPixmap pix(":/resources/image/header-object.png");
    ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/resources/sounds/Гражданская Оборона - Свой среди чужих.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    //music->play();

    connect(music, &QMediaPlayer::mediaStatusChanged, this, [=]() {
          qDebug() << "Media Status:" << music->mediaStatus();
    });
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
    testWindow->show();  // Показываем  окно с тестами
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

void MainWindow::on_button_mus_clicked()
{
    if (mus) {
        //music->pause();
        ui->button_mus->setIcon(QIcon(":/resources/image/sound off.png"));
        ui->button_mus->setIconSize(QSize(50, 50));
    }
    else {
        //music->play();
        ui->button_mus->setIcon(QIcon(":/resources/image/sound on.png"));
        ui->button_mus->setIconSize(QSize(50, 50));
    }
    mus = !mus;
}
