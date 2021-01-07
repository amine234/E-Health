#include "medecin.h"
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
medecin::medecin()
{

}


medecin::medecin(QString ID, QString nom, QString prenom,QString date)
{   this->ID=ID;
    this->nom=nom;
    this->prenom=prenom;
    this->date=date;
}


bool medecin ::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO MEDECIN (ID,nom ,prenom,date) " "values(:ID,:nom, :prenom, :date)");
    query.bindValue(":ID",ID);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date",date);


 return query.exec();


}


bool medecin::supprimer(QString ID)
{
QSqlQuery query;

query.prepare("Delete from MEDECIN where ID=:ID ");
query.bindValue(":ID", ID);
return    query.exec();
}

bool medecin::modifier()
{
    QSqlQuery query;

        query.prepare("Update MEDECIN set NOM=:nom,PRENOM=:prenom, date=:date where ID=:ID");
        query.bindValue(":ID",ID);
        query.bindValue(":NOM",nom);
        query.bindValue(":PRENOM",prenom);
        query.bindValue(":date",date);
        return       query.exec()  ;

  }

QSqlQueryModel *medecin ::afficher()
    {
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select ID,NOM,PRENOM,DATE from MEDECIN");
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));


       return  model;
}

QSqlQueryModel * medecin::rechercher (const QString &aux)

{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from MEDECIN where ((ID||NOM||PRENOM||DATE) LIKE '%"+aux+"%')");
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));


    return  model;
}



QSqlQueryModel *  medecin::trie(const QString &critere, const QString &mode )
{

    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MEDECIN order by "+critere+" "+mode+"");
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE"));


return  model;
}



