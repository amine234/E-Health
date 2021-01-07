#include "fiche_patient.h"

#include "QSqlRecord"
#include<QMessageBox>
#include<QSqlRecord>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>

Fiche::Fiche()
{

}
Fiche::Fiche(QString id,QString nom ,QString prenom,QString adresse,QString groupe_sanguin,int age,int poids,int taille)
{
    this->id = id ;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->groupe_sanguin = groupe_sanguin;
    this->age= age;
    this->poids = poids;
    this->taille = taille;



}

bool Fiche::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO PATIENT(id,nom,prenom,adresse,groupe_sanguin,age,poids,taille) "
                      "VALUES (:id,:nom,:prenom,:adresse,:groupe_sanguin,:age,:poids,:taille)");
        query.bindValue(":id",id);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":adresse",adresse);
        query.bindValue(":groupe_sanguin",groupe_sanguin);
        query.bindValue(":age",age);
        query.bindValue(":poids",poids);
        query.bindValue(":taille",taille);


        return    query.exec();

}
QSqlQueryModel * Fiche ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PATIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("GROUPE_SANGUIN "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));


        return model;
}
bool Fiche:: supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("Delete from PATIENT where id = :id");
    query.bindValue(":id",id);
    return    query.exec();

}

bool Fiche::modifier()
{
    QSqlQuery query;
    QString r = QString::number(age);
    QString r1 = QString::number(poids);
     QString r2 = QString::number(taille);

    query.prepare("UPDATE PATIENT SET NOM=:nom,prenom=:prenom,ADRESSE=:adresse,GROUPE_SANGUIN=:groupe,AGE=:age,taille=:taille,poids=:poids where id=:id ");

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":groupe",groupe_sanguin);
    query.bindValue(":age",r);
    query.bindValue(":poids",r1);
    query.bindValue(":taille",r2);
      return    query.exec();
}

QSqlQueryModel *  Fiche::rechercheparnom(QString nom)
{

    QSqlQueryModel *model = new QSqlQueryModel;
       model->setQuery("SELECT * FROM PATIENT WHERE (nom LIKE '%"+nom+"%')");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("GROUPE_SANGUIN "));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));
        return model ;

 }
QSqlQueryModel *  Fiche::rechercheparadresse(QString adresse)
{

    QSqlQueryModel *model = new QSqlQueryModel;
       model->setQuery("SELECT * FROM PATIENT WHERE (adresse LIKE '%"+adresse+"%')");

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("GROUPE_SANGUIN "));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));
       return model ;
 }
QSqlQueryModel *  Fiche::recherchepargroupesanguin(QString groupe_sanguin)
{

    QSqlQueryModel *model = new QSqlQueryModel;
       model->setQuery("SELECT * FROM PATIENT WHERE (GROUPE_SANGUIN LIKE '%"+groupe_sanguin+"%')");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("GROUPE_SANGUIN "));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));
       return model ;

 }

QSqlQueryModel * Fiche::triparnom()

{

   QSqlQueryModel *model = new QSqlQueryModel;
  model->setQuery("SELECT * FROM PATIENT ORDER BY NOM asc ");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("GROUPE_SANGUIN "));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));

  return model;
}
QSqlQueryModel * Fiche::triparadresse()

{

   QSqlQueryModel *model = new QSqlQueryModel;
   model->setQuery("SELECT * FROM PATIENT ORDER BY ADRESSE asc ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("GROUPE_SANGUIN "));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));

  return model;
}
QSqlQueryModel * Fiche::tripargroupesanguin()

{

   QSqlQueryModel *model = new QSqlQueryModel;
   model->setQuery("SELECT * FROM PATIENT ORDER BY GROUPE_SANGUIN asc ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("GROUPE_SANGUIN "));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));

  return model;
}
void Fiche::imprimer()
{
    QString fileName= QFileDialog::getSaveFileName((QWidget*)0, "Export PDF",QString(),"*.pdf");
    if(QFileInfo(fileName).suffix().isEmpty()){fileName.append(".pdf");}
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM patient");
    q.exec();
    QString pdf="<br> <h1 style='color:red'> LISTE DES PATIENTS <br></h1>\n <br> <table> <tr> <th>NOM </th> <th>PRENOM </th> <th> ID</th> <th>NSS </th>";
    while(q.next())
    {
            pdf=pdf+"<br> <tr> <td>"+q.value(0).toString()+" "+q.value(1).toString()+" "+q.value(2).toString()+" "+q.value(3).toString()+" "+q.value(4).toString()+" "+q.value(5).toString()+" "+q.value(6).toString()+" "+q.value(7).toString()+" "+q.value(8).toString()+" ""</td>";
           }
            doc.setHtml(pdf);
            doc.setPageSize(printer.pageRect().size());
            doc.print(&printer);
}

