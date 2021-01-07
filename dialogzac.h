#ifndef DIALOGZAC_H
#define DIALOGZAC_H
#include <QMessageBox>
#include <QDialog>
#include "ordon.h"
#include "materiel.h"
#include <QPrinter>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextDocument>

namespace Ui {
class Dialogzac;
}

class Dialogzac : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogzac(QWidget *parent = nullptr);
    ~Dialogzac();

private:
    Ui::Dialogzac *ui;

private slots:
    void on_L_Add_clicked();

       void on_pushButton_BACK_clicked();

       void on_pushButton_clicked();

       void on_pushButton_2_clicked();

       void on_L_BACK_clicked();

       void on_L_delete_clicked();

       void on_L_modify_clicked();

       void on_L_search_2_clicked();

       void on_L_search_clicked();

       void on_L_BACK_2_clicked();

       void on_pushButton_5_clicked();

       void on_pushButton_11_clicked();

       void on_pushButton_7_clicked();

       void on_L_BACK_3_clicked();

       void on_L_modify_2_clicked();

       void on_L_delete_2_clicked();

       void on_lineEdit_18_cursorPositionChanged(int arg1, int arg2);

       void on_lineEdit_17_cursorPositionChanged(int arg1, int arg2);

       void on_pushButton_ajouter_emp_clicked();

       void on_pushButton_affich_emp_clicked();

       void on_pushButton_modif_emp_clicked();

       void on_pushButton_supprimer_emp_clicked();

       void on_pushButton_trier_salaire_clicked();

       void on_recherche_critere_emp_clicked();

       void on_pushButton_ajouter_mat_clicked();

       void on_pushButton_modiffier_materiel_clicked();

       void on_pushButton_afficher_materiel_clicked();

       void on_pushButton_ajouter_mate_clicked();

       void on_pushButton_afficher_materiele_clicked();

       void on_pushButton_afficher_materielEE_clicked();

       void on_pushButton_supprimer_rdv_clicked();

       void on_pushButton_modiffier_rdv_clicked();

       void on_pushButton_pdf_rdv_clicked();
};

#endif // DIALOGZAC_H
