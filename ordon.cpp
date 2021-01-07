#include "ordon.h"



ordon::ordon(QString nom,QString prenom,QString medicament,int id)
{
this->nom=nom;
    this->prenom=prenom;
    this->medicament=medicament;
    this->id=id;
}
bool ordon::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);

     query.prepare("INSERT INTO ordon (ID, NOM, PRENOM,medicament) "
                        "VALUES (:id, :nom, :prenom, :medicament)");
    query.bindValue(":id", res);

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":medicament", medicament);



    return    query.exec();

}



QSqlQueryModel * ordon::afficher()
{
    {QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from ordon");
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));

    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("medicament "));

        return model;
    }
}
bool ordon::supprimer(int idd)
{

    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from ordon where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}

bool ordon::modifier(int id,QString nom, QString prenom,QString medicament )
{
    QSqlQuery query;
    QString res= QString::number(id);

    query.prepare("update ordon set nom=:nom,prenom=:prenom, medicament=:medicament where id=:id");
    query.bindValue(":id", res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":medicament", medicament);
    return query.exec();
}
QSqlQueryModel* ordon::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from ordon ORDER BY ID asc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" NOM"));

         model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));


    return model;
}

QSqlQueryModel* ordon::trie2()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from ordon ORDER BY ID desc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" NOM"));

         model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));


    return model;
}

QSqlQueryModel * ordon::chercher_emp(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from ordon where ((id ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("SALAIRE"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("ADRESSE"));

    return model;
}


/*QSqlQueryModel * ordon::chercher_emp1(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from ordon where ((salaire ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("SALAIRE"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("ADRESSE"));

    return model;
}*/

QSqlQueryModel * ordon::chercher_emp2(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from ordon where ((nom ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("SALAIRE"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("ADRESSE"));

    return model;
}
