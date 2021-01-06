#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include"RDV.h"
#include "Facture.h"
#include<QMessageBox>
#include<QTableView>
#include <QApplication>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(R.afficher());
    ui->tableView_2->setModel(F.afficher());

    QTimer *timer_p=new QTimer(this);
          connect(timer_p,SIGNAL(timeout()),this,SLOT(showTime()));
          timer_p->start();
          //DAate systeme
          QDateTime Date_p=QDateTime::currentDateTime();
          QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
          ui->Date->setText(Date_txt);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_txt=time.toString("hh:mm:ss");
    ui->Timer->setText(time_txt);
}


void MainWindow::on_pushButton_AR_clicked()
{int IDP1=ui->lineIDP1->text().toUInt();int IDM=ui->lineIDM->text().toUInt();int DR=ui->lineDR->text().toUInt();QString Su=ui->lineSu->text();
    RDV R  (IDP1,IDM,DR,Su);
        R.ajouter();
          ui->tableView->setModel(R.afficher());
}

void MainWindow::on_pushButton_MR_clicked()
{int IDP1=ui->lineIDP1->text().toUInt();QString Su=ui->lineSu->text();
    bool    test=R.modifier(IDP1,Su) ;
        if (test)
        {
              ui->tableView->setModel(R.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification établie"),
                                 QMessageBox::Ok);}
        else{
        //qDebug()<<"connexion echouer";
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("modification non établie"),
                                QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_SR_clicked()
{
    bool    test=R.supprimer( ui->lineIDP1->text().toUInt());
        if (test)
        {
            ui->tableView->setModel(R.afficher());

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        //qDebug()<<"connexion echouer";
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_AF_clicked()
{int ID2=ui->lineIDP2->text().toUInt();int DF=ui->lineDF->text().toUInt();QString SE=ui->lineSe->text();QString MP=ui->lineMP->text();QString L=ui->lineL->text();
    Facture F  (ID2,DF,SE,MP,L);
        F.ajouter();
          ui->tableView_2->setModel(F.afficher());
}
void MainWindow::on_pushButton_MF_clicked()
{ int ID2=ui->lineIDP2->text().toUInt();QString L=ui->lineL->text();
    bool    test=F.modifier(ID2,L) ;
        if (test)
        {
              ui->tableView_2->setModel(F.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification établie"),
                                 QMessageBox::Ok);}
        else{
        //qDebug()<<"connexion echouer";
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("modification non établie"),
                                QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_SF_clicked()
{
    bool    test=F.supprimer( ui->lineIDP2->text().toUInt());
        if (test)
        {
            ui->tableView_2->setModel(F.afficher());

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        //qDebug()<<"connexion echouer";
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_RR_clicked()
{
    RDV R;
        int id = ui->lineIDP1->text().toInt();
       ui->tableView->setModel(R.rechercher(id));
}

void MainWindow::on_pushButtonRF_clicked()
{
    Facture F;
        int id = ui->lineIDP2->text().toInt();
       ui->tableView_2->setModel(F.rechercher(id));
}

void MainWindow::on_pushButton_TR_clicked()
{
    RDV R;

        bool test=true;
                if(test){

                       { ui->tableView->setModel(R.trier_Idpatient1());
                        QMessageBox::information(nullptr, QObject::tr("trier equipement"),
                                    QObject::tr(" equipement trier.\n"
                                                "Voulez-vous enregistrer les modifications ?"),
                                           QMessageBox::Save
                                           | QMessageBox::Cancel,
                                          QMessageBox::Save);
        }

                    }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("trier  equipement"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButtonTF_clicked()
{
    Facture F;

        bool test=true;
                if(test){

                       { ui->tableView_2->setModel(F.trier_Idpatient2());
                        QMessageBox::information(nullptr, QObject::tr("trier equipement"),
                                    QObject::tr(" equipement trier.\n"
                                                "Voulez-vous enregistrer les modifications ?"),
                                           QMessageBox::Save
                                           | QMessageBox::Cancel,
                                          QMessageBox::Save);
        }

                    }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("trier  equipement"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_mail_clicked()
{
    mail* smtp = new mail("projet.esprit11@gmail.com", "esprit2020", "smtp.gmail.com", 465);

            smtp->sendMail("projet.esprit11@gmail.com", ui->ecrire_mail->text() , ui->ecrire_objet->text() ,ui->ecrire_txt->toPlainText());
}

void MainWindow::on_pushButtonPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Open PDF", QString(), "*.pdf");
                        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("Commande.pdf"); }

                        QPrinter printer(QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                        printer.setPaperSize(QPrinter::A4);
                        printer.setOutputFileName(fileName);

                        QTextDocument doc;
                        QSqlQuery q;
                        q.prepare("SELECT * from FACTURE");
                        q.exec();
                QString pdf="<br> <body style='background-color:LightYellow'> <h1  style='color:DarkKhaki'>  Liste des factures :  <br></h1>\n <br>  <table>  <tr><th>ID      </th>   <th> DATE </th>     <th> SERVICE</th>   <th> MODE PAIMENT</th>  <th> LIBELLE</th>  </tr>" ;


                        while ( q.next()) {

                       pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString()+" </td>     <td>    "  +q.value(2).toString() +"   </td>  <td>     "   +q.value(3).toString()+"</td>   <td>     "   +q.value(4).toString()+"</td>    </td>" ;

                        }
                        doc.setHtml(pdf);
                        doc.setPageSize(printer.pageRect().size());
                        doc.print(&printer);
}
