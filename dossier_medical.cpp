#include "dossier_medical.h"

#include "QSqlRecord"
#include<QMessageBox>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include<QSqlRecord>
Dossier::Dossier()
{

}
Dossier::Dossier(QString id,QString nom ,QString prenom,QString type_de_maladie,QString historique_des_maladies,int age,int poids,int taille)
{
    this->id = id ;
    this->nom = nom;
    this->prenom = prenom;
    this->type_de_maladie = type_de_maladie;
    this->historique_des_maladies = historique_des_maladies;
    this->age= age;
    this->poids = poids;
    this->taille = taille;

}

bool Dossier::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO DOSSIER(id,nom,prenom, type_de_maladie, historique_des_maladies, age, poids, taille) "
                      "VALUES (:id,:nom,:prenom,:type_de_maladie,:historique_des_maladies,:age,:poids,:taille)");
         query.bindValue(":id",id);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":type_de_maladie",type_de_maladie);
         query.bindValue(":historique_des_maladies",historique_des_maladies);
        query.bindValue(":age",age);
        query.bindValue(":poids",poids);
        query.bindValue(":taille",taille);


        return    query.exec();

}
QSqlQueryModel * Dossier ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from DOSSIER");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE DE MALADIE "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("HISTORIQUE DES MALADIES"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));

        return model;
}
bool Dossier:: supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("Delete from DOSSIER where id = :id");
    query.bindValue(":id",id);
    return    query.exec();

}

bool Dossier::modifier()
{
    QSqlQuery query;
    QString r = QString::number(age);
    QString r1 = QString::number(poids);
     QString r2 = QString::number(taille);

    query.prepare("UPDATE DOSSIER SET NOM=:nom,prenom=:prenom,TYPE_DE_MALADIE=:type,HISTORIQUE_DES_MALADIES=:hist,AGE=:age,taille=:taille,poids=:poids where id=:id ");

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":type",type_de_maladie);
    query.bindValue(":hist",historique_des_maladies);
    query.bindValue(":age",r);
     query.bindValue(":poids",r1);
      query.bindValue(":taille",r2);
      return    query.exec();
}
QSqlQueryModel *  Dossier::rechercheparnom(QString nom)
{

    QSqlQueryModel *model = new QSqlQueryModel;
       model->setQuery("SELECT * FROM DOSSIER WHERE (nom LIKE '%"+nom+"%')");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE DE MALADIE "));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("HISTORIQUE DES MALADIES"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));
        return model ;

 }
QSqlQueryModel *  Dossier::rechercheparid(QString id)
{

    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM DOSSIER WHERE (id LIKE '%"+id+"%')");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE DE MALADIE "));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("HISTORIQUE DES MALADIES"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));
        return model ;

 }
QSqlQueryModel *  Dossier::recherchepartypedemaladie(QString type_de_maladie)
{

    QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM DOSSIER WHERE (type_de_maladie LIKE '%"+type_de_maladie+"%')");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE DE MALADIE "));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("HISTORIQUE DES MALADIES"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));
        return model ;

 }
QSqlQueryModel * Dossier::triparnom()

{

   QSqlQueryModel *model = new QSqlQueryModel;
   model->setQuery("SELECT * FROM DOSSIER ORDER BY NOM asc ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE DE MALADIE "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("HISTORIQUE DES MALADIES"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));

  return model;
}
QSqlQueryModel * Dossier::triparid()

{

   QSqlQueryModel *model = new QSqlQueryModel;
   model->setQuery("SELECT * FROM DOSSIER ORDER BY ID asc ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE DE MALADIE "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("HISTORIQUE DES MALADIES"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));

  return model;
}
QSqlQueryModel * Dossier::tripartypedemaladie()

{

   QSqlQueryModel *model = new QSqlQueryModel;
   model->setQuery("SELECT * FROM DOSSIER ORDER BY TYPE_DE_MALADIE asc ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID "));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE DE MALADIE "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("HISTORIQUE DES MALADIES"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("POIDS "));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("TAILLE"));

  return model;
}
void Dossier::imprimer()
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
    QString pdf="<br> <h1 style='color:red'> LISTE DES DOSSIERS <br></h1>\n <br> <table> <tr> <th>NOM </th> <th>PRENOM </th> <th> ID</th> <th>NSS </th>";
    while(q.next())
    {
            pdf=pdf+"<br> <tr> <td>"+q.value(0).toString()+" "+q.value(1).toString()+" "+q.value(2).toString()+" "+q.value(3).toString()+" "+q.value(4).toString()+" "+q.value(5).toString()+" "+q.value(6).toString()+" "+q.value(7).toString()+" "+q.value(8).toString()+" ""</td>";
           }
            doc.setHtml(pdf);
            doc.setPageSize(printer.pageRect().size());
            doc.print(&printer);
}
