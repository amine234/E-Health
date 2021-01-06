#include "RDV.h"
#include "Facture.h"
#include "QSqlRecord"
#include<QMessageBox>
#include<QSqlRecord>
#include <QString>
#include <QSqlQuery>
RDV ::  RDV()
{

}
  RDV::RDV( int  Idpatient1 ,int Idmedecin , int DateR , QString sujet  )
{
      this->Idpatient1 = Idpatient1;
     this-> Idmedecin = Idmedecin;
    this->DateR = DateR;
    this->sujet = sujet;



 }

bool RDV::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO RDV (ID_PATIENT,ID_MEDECIN,DATER, SUJET) "
                      "VALUES (:id_patient,:id_medecin,:dater,:sujet)");
        query.bindValue(":id_patient",Idpatient1);
        query.bindValue(":id_medecin",Idmedecin);
        query.bindValue(":dater",DateR);
        query.bindValue(":sujet",sujet);






        return    query.exec();



}
QSqlQueryModel *RDV ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RDV ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PATIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_MEDECIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATER"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SUJET"));



  return model;
}

bool RDV :: supprimer(int Idpatient1 )
{
    QSqlQuery query;
    query.prepare("Delete from RDV where id_patient = :id_patient");
    query.bindValue(":id_patient",Idpatient1);
    return    query.exec();

}

bool RDV :: modifier (int Idpatient1, QString sujet)
{
    QSqlQuery query;



    query.prepare("UPDATE RDV SET sujet=:sujet where id_patient= :id_patient ");
    query.bindValue(":id_patient",Idpatient1);
    query.bindValue(":sujet",sujet);


       return    query.exec();

}


QSqlQueryModel *  RDV::rechercher(int  Idpatient1)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString z=QString::number( Idpatient1);
    model->setQuery("select * from   RDV where (id_patient LIKE '"+z+"%' ) ");


            return  model;


}
QSqlQueryModel * RDV::trier_Idpatient1()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from RDV ORDER BY ID_PATIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_patient"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_medecin"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("dater"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("sujet"));
        return model;
}
