#include "service.h"
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>

service::service()
{

}


service::service(QString ID, int telephone, QString email)
{   this->ID=ID;
    this->telephone=telephone;
    this->email=email;

}


bool service ::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO SERVICE (ID,telephone ,email) " "values(:ID,:nom, :prenom, :date)");
    query.bindValue(":ID",ID);
    query.bindValue(":telephone",telephone);
    query.bindValue(":email",email);



 return query.exec();


}


bool service::supprimer(QString ID)
{
QSqlQuery query;

query.prepare("Delete from SERVICE where ID=:ID ");
query.bindValue(":ID", ID);
return    query.exec();
}

bool service::modifier()
{
    QSqlQuery query;

        query.prepare("Update SERVICE set TELEPHONE=:telephone,EMAIL=:email, where ID=:ID");
        query.bindValue(":ID",ID);
        query.bindValue(":telephone",telephone);
        query.bindValue(":email",email);

        return       query.exec()  ;

  }

QSqlQueryModel *service ::afficher()
    {
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select ID,TELEPHONE,EMAIL,from SERVICE");
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("telephone"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("email"));



       return  model;
}

QSqlQueryModel * service::rechercher (const QString &aux)

{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from SERVICE where ((ID||TELEPHONE||EMAIL) LIKE '%"+aux+"%')");
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMAIL"));



    return  model;
}



QSqlQueryModel *  service::trie(const QString &critere, const QString &mode )
{

    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from SERVICE order by "+critere+" "+mode+"");
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TELEPHONE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMAIL"));


return  model;
}



