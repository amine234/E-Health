#include "Facture.h"
#include "QSqlRecord"
#include<QMessageBox>
#include<QSqlRecord>
#include <QString>
#include <QSqlQuery>
Facture :: Facture()
{

}
   Facture::Facture( int Idpatient2 , int DateF , QString Service , QString Modepaiment , QString Libelle )
{

    this->Idpatient2 = Idpatient2;
    this->DateF = DateF;
    this->Service =Service;
       this->Modepaiment =Modepaiment;
       this->Libelle =Libelle;



 }

bool Facture ::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO FACTURE (ID_PATIENT,DATE_FACTURE,SERVICE,MODE_PAIMENT,LIBELLE) VALUES (:id_patient2,:date_facture,:service,:mode_paiment,:libelle);");
        query.bindValue(":id_patient2",Idpatient2);
        query.bindValue(":date_facture",DateF);
        query.bindValue(":service",Service);
        query.bindValue(":mode_paiment",Modepaiment);
        query.bindValue(":libelle",Libelle);





        return    query.exec();



}
QSqlQueryModel * Facture ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from FACTURE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PATIENT"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FACTURE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SERVICE "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MODE_PAIMENT "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LIBELLE "));


  return model;
}

bool Facture :: supprimer(int Idpatient2 )
{
    QSqlQuery query;
    query.prepare("Delete from FACTURE where id_patient = :id_patient");
    query.bindValue(":id_patient",Idpatient2);
    return    query.exec();

}

bool Facture ::modifier(int Idpatient2, QString Libelle)
{
    QSqlQuery query;



    query.prepare("UPDATE FACTURE SET libelle=:libelle where id_patient= :id_patient ");
    query.bindValue(":id_patient",Idpatient2);
    query.bindValue(":libelle", Libelle);


       return    query.exec();

}


QSqlQueryModel *  Facture::rechercher(int  Idpatient2)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString x=QString::number( Idpatient2);
    model->setQuery("select * from FACTURE where (id_patient LIKE '"+x+"%' ) ");


            return  model;


}
QSqlQueryModel * Facture::trier_Idpatient2()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from FACTURE ORDER BY ID_PATIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_patient"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_facture"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("service"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("mode_paiment"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("libelle"));
        return model;
}
