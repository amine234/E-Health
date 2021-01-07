#include "dialogyosr.h"
#include "ui_dialogyosr.h"
#include <QMessageBox>
#include "medecin.h"
#include "service.h"
#include <QPixmap>
#include <QMovie>
#include <QMediaPlayer>
#include<QtMultimedia>
#include<QSound>
#include<QPrintDialog>
#include<QPrinter>

Dialogyosr::Dialogyosr(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogyosr)
{
    ui->setupUi(this);
}

Dialogyosr::~Dialogyosr()
{
    delete ui;
}


void Dialogyosr::on_pushButton_10_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:/Users/AMINE/Documents/GitHub/E-Health/button-3.mp3"));
           player->setVolume(100);
           player->play();


           QString critere=ui->comboBox_2->currentText();
                      QString mode;
                      if (ui->checkBox_3->checkState()==false)
                  {
                           mode="DESC";
                  }
                       else if(ui->checkBox_4->checkState()==false)
                       {
                           mode="ASC";
                       }
                 // ui->tableView_2->setModel(service.trie(critere,mode));

}



void Dialogyosr::on_comboBox_2_activated(const QString &arg1)
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
           player->setVolume(100);
           player->play();
}

void Dialogyosr::on_pushButton_9_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
           player->setVolume(100);
           player->play();
}

void Dialogyosr::on_pushButton_7_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
           player->setVolume(100);
           player->play();
}

void Dialogyosr::on_pushButton_6_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
           player->setVolume(100);
           player->play();
}

void Dialogyosr::on_pushButton_8_clicked()
{
    /*sound*/
           QMediaPlayer *player = new QMediaPlayer;

           player->setMedia(QUrl::fromLocalFile("C:/Users/user2/Desktop/2A/QT/CRUD_EVENT/button-8.mp3"));
           player->setVolume(100);
           player->play();
}
