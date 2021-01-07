#ifndef ORDON_H
#define ORDON_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class ordon
{
private:
    QString nom, prenom , medicament;
    int id ;
public:
    //constructeurs
    ordon(){};
    ordon(QString,QString,QString,int);
    // getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getmedicament(){return medicament;}
    int getID(){return id;}
    //setters
    void setNom(QString n ){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setmedicament(QString d){medicament=d;}
    void setId(int id){this->id=id;}
    //fonctions de base relative a l'entite ordon
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int , QString ,QString , QString );
    bool supprimer(int);
    QSqlQueryModel* trie();
    QSqlQueryModel* trier(const QString, const QString);
    QSqlQueryModel* trie2();
    QSqlQueryModel *chercher_emp(const QString &aux);
    QSqlQueryModel *chercher_emp1(const QString &aux);
    QSqlQueryModel *chercher_emp2(const QString &aux);








};

#endif // ORDON_H
