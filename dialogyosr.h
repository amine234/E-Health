#ifndef DIALOGYOSR_H
#define DIALOGYOSR_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialogyosr; }
QT_END_NAMESPACE

class Dialogyosr : public QDialog
{
    Q_OBJECT

public:
    Dialogyosr(QWidget *parent = nullptr);
    ~Dialogyosr();

private slots:
    void on_pushButton_10_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_9_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Dialogyosr *ui;
};
#endif // MAINWINDOW_H
