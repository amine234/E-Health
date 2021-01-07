#ifndef SERVICE_H
#define SERVICE_H



#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class service
{
    QString ID;
    int telephone;
    QString email;



public:
    service();
     service(QString,int ,  QString);

     bool ajouter();
         QSqlQueryModel * afficher();
         bool supprimer(QString ID) ;
         bool modifier();
         QSqlQueryModel * rechercher (const QString &aux);
         QSqlQueryModel *  trie(const QString &critere, const QString &mode );
};
#endif // SERVICE_H
