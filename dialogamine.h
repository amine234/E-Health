#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "RDV.h"
#include <QMainWindow>
#include "Facture.h"
#include "mail.h"
#include <QPrinter>
#include <QFileDialog>
#include <QFileInfo>
#include <QTimer>
#include <QDateTime>
#include "ordon.h"
#include "materiel.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Dialogamine; }
QT_END_NAMESPACE

class Dialogamine : public QDialog
{
    Q_OBJECT

public:
    Dialogamine(QWidget *parent = nullptr);
    ~Dialogamine();

private slots:


    void on_pushButton_AR_clicked();

    void on_pushButton_MR_clicked();

    void on_pushButton_SR_clicked();

    void on_pushButton_AF_clicked();

    void on_pushButton_MF_clicked();

    void on_pushButton_SF_clicked();

    void on_pushButton_RR_clicked();

    void on_pushButtonRF_clicked();

    void on_pushButton_TR_clicked();

    void on_pushButtonTF_clicked();

    void on_pushButton_mail_clicked();

    void on_pushButtonPDF_clicked();

    void  showTime();
//**************************************************



    void on_commandLinkButton_clicked();

private:
    RDV R ;
    Facture F;
    Ui::Dialogamine *ui;
};
#endif // MAINWINDOW_H
