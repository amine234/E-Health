#ifndef RDV_H
#define RDV_H
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
class RDV
{
    QString sujet;
          int Idpatient1, Idmedecin , DateR ;
    public:
        RDV();
             //constructor

                RDV(int , int ,int , QString );
                int getIdpatient1(){return Idpatient1; }
                int getIdmedecin(){return Idmedecin; }
                int getDateR(){return DateR; }
                QString getsujet(){return sujet;}


                // methodes
                bool ajouter();
                QSqlQueryModel * afficher();
                bool supprimer(int);
                bool modifier(int, QString);

                    QSqlQueryModel * rechercher(int);
                     QSqlQueryModel * trier_Idpatient1();
         };
#endif // RDV_H
