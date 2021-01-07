#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include <QByteArray>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
class Employe
{ QString prenom;
    QString nom;
    QString etatcivile;
    QString position;
    QString adresse;
    QString E_mail;
    QString sexe;
    int id_sociale ;
    int id;
    int nss;
    int cin;
    int telephone;
 QByteArray image;



public:
    Employe();
    Employe(QString,QString,QString,QString,QString,QString,QString,int,int,int,int,int );
    QString get_prenom();
    QString get_nom();
    QString get_etatcivile();
    QString get_position();
    QString get_adresse();
    QString get_email();
    QString get_sexe();
    int get_id();
    int get_idsociale();
    int get_nss();
    int get_telephone();
    int get_cin();
    QByteArray get_image();
    bool supprimer(int);
   bool ajouter();
   bool modifier(int);
   QSqlQueryModel *afficher();
   QSqlQueryModel *afficherRech(QString,QString);
   QSqlQueryModel *tri(QString);
   void imprimer();


};

#endif // EMPLOYE_H
