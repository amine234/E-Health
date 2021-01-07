#include "dialogimen.h"
#include "ui_dialogimen.h"
#include <QPixmap>
#include <QMessageBox>
#include <QtDebug>
#include <QSystemTrayIcon>
#include <QFileDialog>
#include <QSystemTrayIcon>
#include <QComboBox>
Dialogimen::Dialogimen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogimen)

{ui->setupUi(this);
        QPixmap pic("C:/Users/hp/Desktop/2 eme anne/projet c++/Qt/PIC/conge.png");
        ui->label_icopcon->setPixmap(pic);
        QPixmap pix("C:/Users/hp/Desktop/2 eme anne/projet c++/Qt/PIC/employe.png");
           ui->label_ajoutempl_3->setPixmap(pix);
           QPixmap p("C:/Users/hp/Desktop/2 eme anne/projet c++/Qt/PIC/employe-image_standard.png");
           ui->image->setPixmap(p);
ui->comboBox_etatcivil->addItem("célibataire");
ui->comboBox_etatcivil->addItem("marié(e)");
ui->comboBox_etatcivil->addItem("divorcé(e)");
ui->comboBox_sexe->addItem("femme");
ui->comboBox_sexe->addItem("homme");
ui->comboBox_position->addItem("aide soignant");
ui->comboBox_position->addItem("infermier");
ui->comboBox_position->addItem("anesthesiste");
ui->tableView->setModel(E.afficher());
           ui->tableConge->setModel(C.afficher());
           ui->comboBoxtype->addItem("Maladie");
             ui->comboBoxtype->addItem("familiale");
               ui->comboBoxtype->addItem("payés");
ui->tableConge->setModel(C.afficher());
            }
Dialogimen::~Dialogimen()
{
    delete ui;
}


void Dialogimen::on_pushButton_clicked()
{int idConge=ui->lineEdit_idConge->text().toInt();
    QString datedebut=ui->dateEditdebut->text();
    QString datefin=ui->dateEdit_2_datefin->text();
    QString type=ui->comboBoxtype->currentText();
     QString commentaireResponsable=ui->textEdit_CR->toPlainText();
      QString commentaireEmploye =ui->textEdit_CE->toPlainText();
    Conge C(idConge,datedebut,datefin,type,commentaireResponsable,commentaireEmploye);
    bool test=C.ajouter();
    if(test)
    {
        ui->tableConge->setModel(C.afficher());


        QMessageBox::information(nullptr,"ajout congé","Congé ajouté");

    }else
    {QMessageBox::warning(nullptr,"suppression congé","congé n est pas ajouté");
}
}





void Dialogimen::on_pushButton_2_clicked()
{

    QString prenom=ui->lineEdit_prenom->text();
            QString nom=ui->lineEdit_nom->text();
            QString sexe=ui->comboBox_sexe->currentText();
            QString etatcivile=ui->comboBox_etatcivil->currentText();
            QString email=ui->lineEdit_Email->text();
            QString adresse=ui->lineEdit_adresse->text();
            QString position=ui->comboBox_position->currentText();
            int id=ui->lineEdit_ID->text().toInt();
            int idsociale=ui->lineEdit_IDsociale->text().toInt();
            int nss=ui->lineEdit_numsecurite->text().toInt();
            int cin=ui->lineEdit_cin->text().toInt();
           int telephone=ui->lineEdit_Telephone->text().toInt();
 Employe E(prenom ,nom,sexe,etatcivile,email,adresse,position,id,idsociale,nss,cin,telephone);
 ui->tableView->setModel(E.afficher());
 bool test=E.ajouter();
 if(test)
 {


    ui->tableView->setModel(E.afficher());
  //  QSound::play("C:/Users/Noursen amami/Desktop/beep.wav");
    QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                    notifier->setIcon(QIcon("C:/Users/Noursen amami/Desktop/369-3699390_notification-png-notification-icon-png-free-clipart.png"));
                     notifier->show();
                     notifier->showMessage("RDV ajouté","Succés",QSystemTrayIcon::Information,10000);


 }
 else

{
 QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                 notifier->setIcon(QIcon("C:/Users/Noursen amami/Desktop/notification.png"));
                  notifier->show();
                  notifier->showMessage("RDV non ajouté","Echec",QSystemTrayIcon::Information,10000);}

}

void Dialogimen::on_pushButton_3_clicked()
{
    int id=ui->lineEdit->text().toInt();
    bool test=C.supprimer(id);
    ui->tableConge->setModel(C.afficher());
    if(test)
    {



     //  QSound::play("C:/Users/Noursen amami/Desktop/beep.wav");
       QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                       notifier->setIcon(QIcon("C:/Users/Noursen amami/Desktop/369-3699390_notification-png-notification-icon-png-free-clipart.png"));
                        notifier->show();
                        notifier->showMessage("Conge Supprimé","Succés",QSystemTrayIcon::Information,10000);


    }
    else

   {
    QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                    notifier->setIcon(QIcon("C:/Users/Noursen amami/Desktop/notification.png"));
                     notifier->show();
                     notifier->showMessage("Conge non supprimé","Echec",QSystemTrayIcon::Information,10000);}

}

void Dialogimen::on_pushButton_4_clicked()
{
    int id=ui->lineEdit_2->text().toInt();
    bool test=E.supprimer(id);
    if(test)
    {


       ui->tableView->setModel(E.afficher());
     //  QSound::play("C:/Users/Noursen amami/Desktop/beep.wav");
       QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                       notifier->setIcon(QIcon("C:/Users/Noursen amami/Desktop/369-3699390_notification-png-notification-icon-png-free-clipart.png"));
                        notifier->show();
                        notifier->showMessage("Employe Supprimé","Succés",QSystemTrayIcon::Information,10000);


    }
    else

   {
    QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                    notifier->setIcon(QIcon("C:/Users/Noursen amami/Desktop/notification.png"));
                     notifier->show();
                     notifier->showMessage("Employe non supprimé","Echec",QSystemTrayIcon::Information,10000);}
}

void Dialogimen::on_pushButton_5_clicked()
{
    int rech=ui->lineEdit_3->text().toInt();
    QString prenom=ui->lineEdit_prenom->text();
            QString nom=ui->lineEdit_nom->text();
            QString sexe=ui->comboBox_sexe->currentText();
            QString etatcivile=ui->comboBox_etatcivil->currentText();
            QString email=ui->lineEdit_Email->text();
            QString adresse=ui->lineEdit_adresse->text();
            QString position=ui->comboBox_position->currentText();
            int id=ui->lineEdit_ID->text().toInt();
            int idsociale=ui->lineEdit_IDsociale->text().toInt();
            int nss=ui->lineEdit_numsecurite->text().toInt();
            int cin=ui->lineEdit_cin->text().toInt();
           int telephone=ui->lineEdit_Telephone->text().toInt();
 Employe E(prenom ,nom,sexe,etatcivile,email,adresse,position,id,idsociale,nss,cin,telephone);
 bool test=E.modifier(rech);
 ui->tableView->setModel(E.afficher());

}

void Dialogimen::on_pushButton_6_clicked()
{
    int rech=ui->lineEdit_4->text().toInt();
    int idConge=ui->lineEdit_idConge->text().toInt();
        QString datedebut=ui->dateEditdebut->text();
        QString datefin=ui->dateEdit_2_datefin->text();
        QString type=ui->comboBoxtype->currentText();
         QString commentaireResponsable=ui->textEdit_CR->toPlainText();
          QString commentaireEmploye =ui->textEdit_CE->toPlainText();
        Conge C(idConge,datedebut,datefin,type,commentaireResponsable,commentaireEmploye);
        bool test=C.ModifierConge(rech);
        ui->tableConge->setModel(C.afficher());

}

void Dialogimen::on_pushButton_7_clicked()
{
    QString rech=ui->lineEdit_5->text();
    QString selon=ui->comboBox->currentText();

          if (rech.isEmpty()) {
              QMessageBox::information(this, tr("Empty Field"),
                  tr("Please enter a name."));
              return;
          } else {


   ui->tableView->setModel(E.afficherRech(selon,rech));

          }
}

void Dialogimen::on_pushButton_15_clicked()
{
    QString rech=ui->lineEdit_11->text();
    QString selon=ui->comboBox_3->currentText();

          if (rech.isEmpty()) {
              QMessageBox::information(this, tr("Empty Field"),
                  tr("Please enter a name."));
              return;
          } else {


   ui->tableConge->setModel(C.afficherRech(selon,rech));

          }
}

void Dialogimen::on_pushButton_16_clicked()
{
    QString res=ui->comboBox_4->currentText();
    ui->tableView->setModel(E.tri(res));
}

void Dialogimen::on_pushButton_17_clicked()
{
    QString res=ui->comboBox_5->currentText();
    ui->tableConge->setModel(C.tri(res));
}

void Dialogimen::on_pushButton_19_clicked()
{
   E.imprimer();
}

void Dialogimen::on_pushButton_18_clicked()
{
    C.imprimer();
}

void Dialogimen::on_pushButton_8_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("choose"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (QString::compare(filename, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename);
        if (valid)
        {  image=image.scaledToWidth(ui->image->width(),Qt::SmoothTransformation);
            ui->image->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //error handling
        }
    }
}
