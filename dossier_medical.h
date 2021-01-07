#ifndef DOSSIER_MEDICAL_H
#define DOSSIER_MEDICAL_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Dossier
{
    QString id,nom,prenom,type_de_maladie,historique_des_maladies ;
    int age,poids,taille;



public:
       Dossier();
    //constructor

       Dossier(QString,QString,QString,QString,QString,int,int,int);


       QString getid(){return id;}
        QString getnom(){return nom;}
        QString getprenom(){return  prenom;}
        QString gettype_de_maladie(){return type_de_maladie;}
        QString gethistorique_de_maladie(){return historique_des_maladies;}
        int gettaille(){return taille;}
        int getpoids(){return poids;}
        int getage(){return age;}
       // methodes
       bool ajouter();
       QSqlQueryModel * afficher();
       bool supprimer(QString);
       bool modifier();
       QSqlQueryModel * rechercheparnom(QString);
       QSqlQueryModel * rechercheparid(QString);
       QSqlQueryModel * recherchepartypedemaladie(QString);
       QSqlQueryModel * triparnom();
       QSqlQueryModel * triparid();
       QSqlQueryModel * tripartypedemaladie();
      void imprimer();
};


#endif // DOSSIER_MEDICAL_H
