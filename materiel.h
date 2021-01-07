
#ifndef MATERIEL_H
#define MATERIEL_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class materiel
{
private:
    QString type, fournisseur;
    int prix_u , quantite_p,quantite_t;
public:
    //constructeurs
    materiel(){};
    materiel(QString,int,int,int,QString);
    // getters
    QString getTYPE(){return type;}
    QString getFournisseur(){return fournisseur;}
    int getPrix_u(){return prix_u;}
    int getQuantite_p(){return quantite_p;}
    int getQuantite_t(){return quantite_t;}
    //setters
    void setType(QString n ){type=n;}
    void setFournisseur(QString p){fournisseur=p;}
    void setPrix_u(int d){prix_u=d;}
    void setQuantite_p(int id){quantite_p=id;}
    void setQuantite_t(int salaire){quantite_t=salaire;}
    //fonctions de base relative a l'entite materiel
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(QString,int,int,int,QString);
    bool supprimer(QString);
    QSqlQueryModel* trie();
    QSqlQueryModel* trier(const QString, const QString);
    QSqlQueryModel* trie2();





};

#endif // MATERIEL_H
