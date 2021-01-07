#ifndef CONGE_H
#define CONGE_H
#include<qstring.h>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QSqlQueryModel>
using namespace std;
class Conge
{   int idConge;
    QString datedebut;
    QString datefin;
    QString type;
    QString commentaireResponsable;
    QString commentaireEmploye;

public:
    Conge();
    Conge(int,QString,QString,QString,QString,QString);

   QString get_datedebut();
    void setDateDebutConge(QString datedebut)
      {
          this->datedebut = datedebut;
      }

    QString get_datefin();
    void setdatefin(QString datefin)
        {
          this-> datefin = datefin;
        }
    QString get_type();
    void setType(QString type)
        {
            this->type = type;
        }
    QString get_commentaireResponsable();
    void setCommentaireResponsable
        (QString commentaireResponsable)
        {
            this->commentaireResponsable = commentaireResponsable;
        }
    QString get_commentaireEmploye();
    void setCommentaireEmploye
        (QString commentaireEmploye)
        {
            this->commentaireEmploye = commentaireEmploye;
        }
    int getIdConge()
        {
            return idConge;
        }
     void setIdConge(unsigned long long idConge)
     {
         this->idConge= idConge;
     }


bool ajouter();
bool ModifierConge(int);
QSqlQueryModel *afficher();
QSqlQueryModel *afficherRech(QString,QString);
QSqlQueryModel *tri(QString);
bool supprimer(int);
 bool RechercherConge(QString);
void imprimer();


};

#endif // CONGE_H

