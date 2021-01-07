#ifndef DIALOG_H
#define DIALOG_H
#include "conge.h"
#include <QDialog>
#include <employe.h>
namespace Ui {
class Dialogimen;
}

class Dialogimen : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogimen(QWidget *parent = nullptr);
    ~Dialogimen();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Dialogimen *ui;
    Conge C;
    Employe E;
};

#endif // DIALOG_H

