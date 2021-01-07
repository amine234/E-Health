#include "employe.h"

Employe::Employe()
{

}
Employe::Employe(QString prenom,QString nom,QString sexe,QString etatcivile,QString email,QString adresse,QString position,int id,int idsociale,int nss,int cin,int telephone)
{this->prenom=prenom;
    this->nom=nom;
        this->id=id;
            this->id_sociale=idsociale;
            this->nss=nss;
              this->cin=cin;
    this->sexe=sexe;
            this->etatcivile=etatcivile;
    this->E_mail=email;
    this->adresse=adresse;
            this->position=position;
    this->telephone=telephone;
     // this->image=image;

}
bool Employe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO employe1(prenom ,nom,id,idsociale,nss,cin,sexe,etatcivile,email,adresse,position,telephone)VALUES(:prenom,:nom,:id,:idsociale,:nss,:cin,:sexe,:etatcivile,:email,:adresse,:position,:telephone)");
    query.bindValue(":prenom",prenom);
     query.bindValue(":nom",nom);
    QString identity= QString::number(id);
     query.bindValue(":id",id);
     QString ids=QString::number(id_sociale);
      query.bindValue(":idsociale",ids);
     QString n=QString::number(nss);
      query.bindValue(":nss",n);
      QString c=QString::number(cin);
       query.bindValue(":cin",c);
    query.bindValue(":sexe",sexe);
    query.bindValue(":etatcivile",etatcivile);
        query.bindValue(":email",E_mail);
            query.bindValue(":adresse",adresse);
            query.bindValue(":position",position);
            QString tel=QString::number(telephone);
            query.bindValue(":telephone",tel);

return query.exec();
}

QSqlQueryModel *Employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel ();
    model->setQuery("select * from employe1");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("idsociale"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("nss"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("etatcivile"));
      model->setHeaderData(7,Qt::Horizontal,QObject::tr("email"));
      model->setHeaderData(8,Qt::Horizontal,QObject::tr("adresse"));
      model->setHeaderData(9,Qt::Horizontal,QObject::tr("type"));
       model->setHeaderData(10,Qt::Horizontal,QObject::tr("position"));
        model->setHeaderData(11,Qt::Horizontal,QObject::tr("telephone"));
   return model;
}
bool Employe::supprimer(int id){
QSqlQuery query;
query.prepare("Delete from employe1 where id=:id");
query.bindValue(":id",id);
return ((query.exec()));
}
bool Employe::modifier(int rech)
{
    QSqlQuery query;
    QString idsociale=QString::number(id_sociale) ;
    QString iden=QString::number(id);
    QString numss=QString::number(nss);
    QString carteid=QString::number(cin);
    QString tel=QString::number(telephone);

    query.prepare("UPDATE employe1 SET prenom='"+prenom+"' ,nom='"+nom+"',id='"+iden+"',idsociale='"+idsociale+"',nss='"+numss+"',cin='"+carteid+"',sexe='"+sexe+"',etatcivile='"+etatcivile+"',email='"+E_mail+"',adresse='"+adresse+"',position='"+position+"',telephone='"+tel+"' where id=:rech");
    query.bindValue(":rech",rech);

    return query.exec();
}

QSqlQueryModel *Employe::afficherRech(QString a,QString b)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from employe1 where "+a+"='"+b+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("idsociale"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("nss"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("etatcivile"));
      model->setHeaderData(7,Qt::Horizontal,QObject::tr("email"));
      model->setHeaderData(8,Qt::Horizontal,QObject::tr("adresse"));
      model->setHeaderData(9,Qt::Horizontal,QObject::tr("type"));
       model->setHeaderData(10,Qt::Horizontal,QObject::tr("position"));
        model->setHeaderData(11,Qt::Horizontal,QObject::tr("telephone"));
    return model;
}
QSqlQueryModel* Employe::tri(QString arg1)
{
    QSqlQueryModel *model=new QSqlQueryModel();
        if (arg1=="ID")
            model->setQuery("select * from employe1 order by id");
       else if (arg1=="NOM")
            model->setQuery("select * from employe1 order by nom");
       if (arg1=="PRENOM")
            model->setQuery("select * from employe1 order by prenom");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("prenom"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("id"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("idsociale"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("nss"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("etatcivile"));
         model->setHeaderData(7,Qt::Horizontal,QObject::tr("email"));
         model->setHeaderData(8,Qt::Horizontal,QObject::tr("adresse"));
         model->setHeaderData(9,Qt::Horizontal,QObject::tr("type"));
          model->setHeaderData(10,Qt::Horizontal,QObject::tr("position"));
           model->setHeaderData(11,Qt::Horizontal,QObject::tr("telephone"));

   return model;

}

void Employe::imprimer()
{
    QString fileName= QFileDialog::getSaveFileName((QWidget*)0, "Export PDF",QString(),"*.pdf");
    if(QFileInfo(fileName).suffix().isEmpty()){fileName.append(".pdf");}
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM employe1");
    q.exec();
    QString pdf="<br> <h1 style='color:red'> LISTE DES EMPLOYES <br></h1>\n <br> <table> <tr> <th>NOM </th> <th>PRENOM </th> <th> ID</th> <th>NSS </th>";
    while(q.next())
    {
            pdf=pdf+"<br> <tr> <td>"+q.value(0).toString()+" "+q.value(1).toString()+" "+q.value(2).toString()+" "+q.value(3).toString()+" "+q.value(4).toString()+" "+q.value(5).toString()+" "+q.value(6).toString()+" "+q.value(7).toString()+" "+q.value(8).toString()+" "+q.value(9).toString()+" "+q.value(10).toString()+" "+q.value(11).toString()+"</td>";
           }
            doc.setHtml(pdf);
            doc.setPageSize(printer.pageRect().size());
            doc.print(&printer);
}

