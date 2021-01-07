#include "dialogoussema.h"
#include "ui_dialogoussema.h"
#include "fiche_patient.h"
#include "dossier_medical.h"
#include<QMessageBox>
#include<QTableView>
#include <QApplication>

Dialogoussema::Dialogoussema(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogoussema)
{
    ui->setupUi(this);
     ui->tableView->setModel(F.afficher());
     ui->tableView_2->setModel(D.afficher());
}

Dialogoussema::~Dialogoussema()
{
    delete ui;
}


void Dialogoussema::on_pushButton_clicked()
{
    Fiche F  (ui->lineEdit_7->text(),ui->lineEdit_10->text(),ui->lineEdit_11->text(),ui->lineEdit_13->text(),ui->lineEdit_16->text(),ui->lineEdit_12->text().toUInt(),ui->lineEdit_14->text().toUInt(),ui->lineEdit_15->text().toUInt());
        F.ajouter();
          ui->tableView->setModel(F.afficher());

}




void Dialogoussema::on_pushButton_2_clicked()
{

             QString    id=  ui->lineEdit_7->text();
             QString    nom= ui->lineEdit_10->text();
             QString    prenom= ui->lineEdit_11->text();
             QString   adresse= ui->lineEdit_13->text();
             QString groupe=  ui->lineEdit_16->text();
             int  age=  ui->lineEdit_12->text().toInt();
             int  poids= ui->lineEdit_14->text().toInt();
             int  taille=ui->lineEdit_15->text().toInt();
         Fiche F(id,nom,prenom,adresse,groupe,age,poids,taille);
        bool    test=F.modifier() ;
            if (test)
            {
                  ui->tableView->setModel(F.afficher());
                QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("modification établie"),
                                     QMessageBox::Ok);}
            else{
            //qDebug()<<"connexion echouée";
            QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                    QObject::tr("modification non établie"),
                                    QMessageBox::Cancel);}
}


void Dialogoussema::on_pushButton_3_clicked()
{
    bool    test=F.supprimer( ui->lineEdit_7->text());
        if (test)
        {
            ui->tableView->setModel(F.afficher());

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        //qDebug()<<"connexion echouer";
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}
}

void Dialogoussema::on_pushButton_4_clicked()
{
   Dossier D  (ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_8->text(),ui->lineEdit_9->text(),ui->lineEdit_4->text().toUInt(),ui->lineEdit_5->text().toUInt(),ui->lineEdit_6->text().toUInt());
        D.ajouter();
          ui->tableView_2->setModel(D.afficher());

}

void Dialogoussema::on_pushButton_6_clicked()
{
    bool    test=D.supprimer( ui->lineEdit->text());
        if (test)
        {
            ui->tableView_2->setModel(D.afficher());

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        //qDebug()<<"connexion echouer";
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}
}

void Dialogoussema::on_pushButton_7_clicked()
{
        Fiche F;
        ui->tableView->setModel(F.rechercheparnom(ui->lineEdit_17->text()));
}

void Dialogoussema::on_pushButton_8_clicked()
{
    ui->tableView->setModel(F.afficher());
}



void Dialogoussema::on_pushButton_10_clicked()
{
    QString adresse=ui->lineEdit_adresse->text();
    ui->tableView->setModel(F.rechercheparadresse(adresse));
}

void Dialogoussema::on_pushButton_11_clicked()
{
    ui->tableView->setModel(F.recherchepargroupesanguin(ui->lineEdit_19->text()));
}
void Dialogoussema::on_checkBox_clicked()
{
    ui->tableView->setModel(F.triparnom());
}

void Dialogoussema::on_pushButton_12_clicked()
{
    Dossier D;
    ui->tableView_2->setModel(D.rechercheparnom(ui->lineEdit_18->text()));
}

void Dialogoussema::on_pushButton_13_clicked()
{
    ui->tableView_2->setModel(D.rechercheparid(ui->lineEdit_20->text()));
}

void Dialogoussema::on_pushButton_14_clicked()
{
    Dossier D;
    ui->tableView_2->setModel(D.recherchepartypedemaladie(ui->lineEdit_21->text()));
}

void Dialogoussema::on_pushButton_15_clicked()
{
    ui->tableView_2->setModel(D.afficher());
}

void Dialogoussema::on_pushButton_9_clicked()
{
    ui->tableView_2->setModel(D.afficher());
}

void Dialogoussema::on_checkBox_2_clicked()
{
    ui->tableView->setModel(F.triparadresse());
}

void Dialogoussema::on_checkBox_3_clicked()
{
    ui->tableView->setModel(F.tripargroupesanguin());
}

void Dialogoussema::on_checkBox_4_clicked()
{
    ui->tableView_2->setModel(D.triparnom());
}

void Dialogoussema::on_checkBox_5_clicked()
{
    ui->tableView_2->setModel(D.triparid());
}

void Dialogoussema::on_checkBox_6_clicked()
{
    ui->tableView_2->setModel(D.tripartypedemaladie());
}

void Dialogoussema::on_pushButton_16_clicked()
{
    ui->tableView->setModel(F.afficher());
}


void Dialogoussema::on_pushButton_20_clicked()
{
    QString     id=  ui->lineEdit->text();
           QString    nom= ui->lineEdit_2->text();
           QString    prenom= ui->lineEdit_3->text();
            QString   type= ui->lineEdit_8->text();
              QString hist=  ui->lineEdit_9->text();
            int  age=  ui->lineEdit_4->text().toInt();
             int  poids= ui->lineEdit_5->text().toInt();
             int   taille=ui->lineEdit_6->text().toInt();
         Dossier D(id,nom,prenom,type,hist,age,poids,taille);
        bool    test=D.modifier() ;
            if (test)
            {
                  ui->tableView_2->setModel(D.afficher());
                QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("modification établie"),
                                     QMessageBox::Ok);}
            else{
            //qDebug()<<"connexion echouée";
            QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                    QObject::tr("modification non établie"),
                                    QMessageBox::Cancel);}
}

void Dialogoussema::on_pushButton_5_clicked()//imprimer
{
   F.imprimer();
}

void Dialogoussema::on_pushButton_17_clicked()
{
    D.imprimer();
}
