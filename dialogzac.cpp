#include "dialogzac.h"
#include "ui_dialogzac.h"

Dialogzac::Dialogzac(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogzac)
{
    ui->setupUi(this);
}

Dialogzac::~Dialogzac()
{
    delete ui;
}


void Dialogzac::on_pushButton_ajouter_emp_clicked()
{
    {
        ordon h;
        ordon Etmp;
        int id=ui->lineEdit_ID->text().toInt();
        QString nom=ui->lineEdit_NOM->text();
        QString prenom=ui->lineEdit_PRENOM->text();
        QString adresse=ui->lineEdit_DEP->text();

    ordon E(nom,prenom,adresse,id);
    bool test=E.ajouter();
    if(test)
    {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
    }

    }
}

void Dialogzac::on_pushButton_affich_emp_clicked()
{
    ordon Etmp;

    {ui->tableView->setModel(Etmp.afficher());}
}

void Dialogzac::on_pushButton_modif_emp_clicked()
{
    ordon p;
        int id = ui->lineEdit_ID_2->text().toInt();
        QString nom = ui->lineEdit_NOM_2->text();
        QString prenom = ui->lineEdit_PRENOM_2->text();
        QString adresse= ui->lineEdit_SAL_2->text();


        ordon  (nom,prenom,adresse,id) ;
        bool test =p.modifier(id,nom,prenom,adresse);
        if(test)
        {ui->tableView->setModel(p.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                                     QObject::tr("employe  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un employe"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialogzac::on_pushButton_supprimer_emp_clicked()
{
    ordon Etmp;
    Etmp.setId(ui->lineEdit_12->text().toInt());
    QMessageBox msgbox;
        msgbox.setWindowTitle("supprimer");
        msgbox.setText("voulez_vous supprimer cette réclamation?");
        msgbox.setStandardButtons(QMessageBox ::Yes);
        msgbox.addButton(QMessageBox::No);
        if(msgbox.exec()==QMessageBox::Yes)
        {
  bool test=Etmp.supprimer(Etmp.getID());
  QMessageBox msgBox;

  if(test)
  {
      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectuée \n click cancel to exit."), QMessageBox::Cancel);
      {ui->tableView->setModel(Etmp.afficher());}

  }
  else
      QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectuer.\n click cancel to exis."), QMessageBox::Cancel);
  msgBox.exec();

}

}

void Dialogzac::on_pushButton_trier_salaire_clicked()
{
    ordon e;
    /*QString critere=ui->cb_historique->currentText();*/
        QString mode;
         if (ui->rb_asc_historique->isChecked()==true)
    {
             ui->tableView->setModel(e.trie());


    }
         else if(ui->rb_desc_historique->isChecked()==true)

             ui->tableView->setModel(e.trie2());
}

void Dialogzac::on_recherche_critere_emp_clicked()
{
    ordon e;
    QString text;
    if (ui->radioButton_ID->isChecked()==true)
{
text=ui->line_recherche_critere->text();
     if(text == "")

     {

         ui->tableView->setModel(e.afficher());

     }

     else

     {



         ui->tableView->setModel(e.chercher_emp(text));

     }
    }

     else if     (ui->radioButton_nom->isChecked()==true)
     {

         text=ui->line_recherche_critere->text();
              if(text == "")

              {

                  ui->tableView->setModel(e.afficher());

              }

              else

              {



                  ui->tableView->setModel(e.chercher_emp2(text));

              }
     }
}







void Dialogzac::on_pushButton_ajouter_mate_clicked()
{

    QString type=ui->lineEdit_type->text();
    int quantite_t=ui->lineEdit_quantite->text().toInt();

    int prix_u=ui->lineEdit_prix->text().toInt();
    int quantite_p=ui->lineEdit_quantite_panne->text().toInt();
    QString fournisseur=ui->lineEdit_fournisseur->text();


materiel E(type,quantite_t , prix_u,quantite_p,fournisseur);
bool test=E.ajouter();
if(test)
{
    QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
}
}



void Dialogzac::on_pushButton_afficher_materielEE_clicked()
{
    materiel Etmp;

    {ui->tableView_2->setModel(Etmp.afficher());}
}

void Dialogzac::on_pushButton_supprimer_rdv_clicked()
{
    materiel m;
    materiel Etmp;
    m.setType(ui->lineEdit_mt->text());
  bool test=m.supprimer(m.getTYPE());
  QMessageBox msgBox;

  if(test)
  {
      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectuée \n click cancel to exit."), QMessageBox::Cancel);
      {ui->tableView_2->setModel(Etmp.afficher());}

  }
  else
      QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectuer.\n click cancel to exis."), QMessageBox::Cancel);
  msgBox.exec();
}

void Dialogzac::on_pushButton_modiffier_rdv_clicked()
{
    materiel m;



    QString type = ui->lineEdit_type_2->text();
    int quantite_t= ui->lineEdit_quantite_2->text().toInt();
    int prix_u = ui->lineEdit_prix_2->text().toInt();
    int quantite_p= ui->lineEdit_quantite_panne_2->text().toInt();



    QString fournisseur = ui->lineEdit_fournisseur_2->text();



        materiel (type, prix_u,quantite_t,quantite_p,fournisseur) ;
        bool test =m.modifier(type ,quantite_t ,prix_u,quantite_p,fournisseur);
        if(test)
        {ui->tableView->setModel(m.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                                     QObject::tr("employe  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un employe"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialogzac::on_pushButton_pdf_rdv_clicked()
{
    QDialog QFileDialog;
     QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("reclamation.pdf"); }

             QPrinter printer(QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
             printer.setPaperSize(QPrinter::A4);
             printer.setOutputFileName(fileName);

             /*QPrinter printer;*/
             ui->tableView_2->render(&printer);


             QTextDocument doc;
             QSqlQuery q;
             q.prepare("SELECT * FROM reclamation ");
             q.exec();
             QString pdf="<br> <img src='D:/Esprit/2A2/projet c++/logo/debug2.png' height='42' width='144'/> <h1  style='color:red'>LISTE DES RECLAMATION  <br></h1>\n <br> <table>  <tr>  <th> CODE </th> <th> SUJET </th> <th> COMMENTAIRE </th> <th> DATE AJOUT </th>  </tr>" ;


             while ( q.next()) {

                 pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>   <td>   " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>    <td>"+q.value(4).toString()+" </td>" ;

             }
             doc.setHtml(pdf);
             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
          /*   doc.print(&printer);*/
             ui->tableView_2->render(&printer);
}
