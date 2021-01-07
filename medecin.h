#ifndef MEDECIN_H
#define MEDECIN_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class medecin
{
    QString ID;
    QString nom;
    QString prenom;
    QString date;


public:
    medecin();
     medecin(QString, QString ,  QString ,QString);

     bool ajouter();
         QSqlQueryModel * afficher();
         bool supprimer(QString ID) ;
         bool modifier();
         QSqlQueryModel * rechercher (const QString &aux);
         QSqlQueryModel *  trie(const QString &critere, const QString &mode );
};
#endif // MEDECIN_H
