#ifndef FICHE_PATIENT_H
#define FICHE_PATIENT_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Fiche
{
    QString id,nom,prenom,adresse,groupe_sanguin ;
    int age,poids,taille;


public:
       Fiche();
    //constructor

       Fiche(QString,QString,QString,QString,QString,int,int,int);


       QString getid(){return id;}
        QString getnom(){return nom;}
        QString getprenom(){return  prenom;}
        QString getadresse(){return adresse;}
        QString groupesanguin(){return groupe_sanguin;}
        int gettaille(){return taille;}
        int getpoids(){return poids;}
        int getage(){return age;}
       // methodes
       bool ajouter();
       QSqlQueryModel * afficher();
       bool supprimer(QString);
       bool modifier();
       QSqlQueryModel * rechercheparnom(QString);
       QSqlQueryModel * rechercheparadresse(QString);
       QSqlQueryModel * recherchepargroupesanguin(QString);
       QSqlQueryModel * triparnom();
       QSqlQueryModel * triparadresse();
       QSqlQueryModel * tripargroupesanguin();
  void imprimer();
};


#endif // FICHE_PATIENT_H
