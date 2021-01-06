#ifndef FACTURE_H
#define FACTURE_H
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
class Facture
{
    QString Service , Modepaiment , Libelle ;
          int Idpatient2 , DateF ;
    public:
         Facture();
             //constructor

                Facture(int , int , QString , QString , QString);
                int getIdpatient1(){return Idpatient2; }
                int getDateF(){return DateF; }
                QString getService(){return  Service;}
                QString getModepaiment(){return Modepaiment;}
                QString getLibelle(){return  Libelle;}



                // methodes
                bool ajouter();
                QSqlQueryModel * afficher();
                bool supprimer(int);
                bool modifier(int,QString);

                    QSqlQueryModel * rechercher(int);
                     QSqlQueryModel * trier_Idpatient2();
         };
#endif // FACTURE_H
