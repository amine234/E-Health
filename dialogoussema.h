#ifndef DIALOGOUSSEMA_H
#define DIALOGOUSSEMA_H


#include"fiche_patient.h"
#include "dossier_medical.h"
#include<QMessageBox>
#include<QTableView>
#include <QDialog>


namespace Ui {
class Dialogoussema;
}

class Dialogoussema : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogoussema(QWidget *parent = nullptr);
    ~Dialogoussema();


private slots:
    void on_pushButton_clicked();


    void on_tabWidget_2_currentChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();



    void on_radioButton_clicked();

    void on_checkBox_clicked();





    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_9_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_checkBox_6_clicked();

    void on_checkBox_7_clicked();

    void on_checkBox_9_clicked();

    void on_checkBox_8_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_20_clicked();

private:
   Fiche F;
   Dossier D;
    Ui::Dialogoussema *ui;
};
#endif // MAINWINDOW_H
