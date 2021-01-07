#include "menu.h"
#include "ui_menu.h"
#include "dialogamine.h"
#include "dialogzac.h"
#include "dialogimen.h"
#include "dialogoussema.h"
#include "dialogyosr.h"
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
  hide();
Dialogamine Da;
Da.setModal(true);
Da.exec();
}

void menu::on_pushButton_2_clicked()
{
    hide();
  Dialogzac Dz;
  Dz.setModal(true);
  Dz.exec();
}

void menu::on_pushButton_3_clicked()
{
    hide();
  Dialogimen Di;
  Di.setModal(true);
  Di.exec();
}

void menu::on_pushButton_4_clicked()
{
    hide();
  Dialogoussema Do;
  Do.setModal(true);
  Do.exec();
}

void menu::on_pushButton_5_clicked()
{
    hide();
  Dialogyosr Dy;
  Dy.setModal(true);
  Dy.exec();
}
