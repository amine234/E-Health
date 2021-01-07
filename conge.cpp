#include "conge.h"
#include<QSqlQuery>
#include <QSqlQueryModel>
Conge::Conge()
{

}
Conge::Conge(int idConge,QString datedebut,QString datefin,QString type , QString commentaireResponsable, QString commentaireEmploye)
{ this->idConge=idConge;
    this->datedebut=datedebut;
   this-> datefin =datefin;
   this-> type= type;
    this->commentaireResponsable=commentaireResponsable;
    this->commentaireEmploye=commentaireEmploye;


}
bool Conge::ajouter()
{QSqlQuery query;
    QString d=QString::number(idConge);
query.prepare("INSERT INTO conge(datedebut,commentaireResponsable,datefin,commentaireEmploye,idconge,type)VALUES(:datedebut,:commentaireResponsable,:datefin,:commentaireEmploye,:idconge,:type)");
query.bindValue(":idconge",d);
query.bindValue(":datedebut",datedebut);
query.bindValue(":datefin",datefin);
query.bindValue(":type",type);
query.bindValue(":commentaireResponsable",commentaireResponsable);
      query.bindValue(":commentaireEmploye",commentaireEmploye);
return query.exec();}
QSqlQueryModel * Conge::afficher()
 {
 QSqlQueryModel * model= new QSqlQueryModel ();
 model->setQuery("select * from Conge");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("DATE_DEBUT"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("COMMENTAIRE_RESP"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("date fin"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("COMMENTAIRE_EMP"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_conge"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("type"));


      return model;


 }

bool Conge::ModifierConge(int rech){
QSqlQuery query;
QString idc=QString::number(idConge);
query.prepare("UPDATE conge SET datedebut='"+datedebut+"',commentaireResponsable='"+commentaireResponsable+"',datefin='"+datefin+"',commentaireEmploye='"+commentaireEmploye+"',idconge='"+idc+"',type='"+type+"' where idconge=:rech");
query.bindValue(":rech",rech);

return ((query.exec()));
}
bool Conge::supprimer(int id){
QSqlQuery query;
query.prepare("Delete from conge where idconge=:id");
query.bindValue(":id",id);
return ((query.exec()));
}
QSqlQueryModel *Conge::afficherRech(QString a,QString b)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from conge where "+a+"='"+b+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("DATE_DEBUT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("COMMENTAIRE_RESP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date fin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("COMMENTAIRE_EMP"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_conge"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("type"));
    return model;
}
QSqlQueryModel* Conge::tri(QString arg1)
{
    QSqlQueryModel *model=new QSqlQueryModel();
        if (arg1=="ID")
            model->setQuery("select * from conge order by idconge");
       else if (arg1=="DATE_DEBUT")
            model->setQuery("select * from conge order by datedebut");
       if (arg1=="TYPE")
            model->setQuery("select * from conge order by type");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("DATE_DEBUT"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("COMMENTAIRE_RESP"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("date fin"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("COMMENTAIRE_EMP"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_conge"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("type"));

   return model;
}
void Conge::imprimer()
{
    QString fileName= QFileDialog::getSaveFileName((QWidget*)0, "Export PDF",QString(),"*.pdf");
    if(QFileInfo(fileName).suffix().isEmpty()){fileName.append(".pdf");}
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM conge");
    q.exec();
    QString pdf="<br> <h1 style='color:red'> LISTE DES CONGES <br></h1>\n <br> <table> <tr> <th>DATE DEBUT </th> <th>COMMENTAIRE RESPONSABLE </th> <th>DATE FIN</th> <th>COMMENTAIRE EMPLOYE </th> <th> ID </th> <th> TYPE </th>";
    while(q.next())
    {
            pdf=pdf+"<br> <tr> <td>"+q.value(0).toString()+" "+q.value(1).toString()+" "+q.value(2).toString()+" "+q.value(3).toString()+" "+q.value(4).toString()+" "+q.value(5).toString()+"</td>";
           }
            doc.setHtml(pdf);
            doc.setPageSize(printer.pageRect().size());
            doc.print(&printer);
}


