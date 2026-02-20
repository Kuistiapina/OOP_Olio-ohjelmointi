#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   void setEditNum(int num);

private slots:
    void on_plussa_pushButton_clicked();

    void on_miinus_pushButton_clicked();

    void on_ykkonen_pushButton_clicked();

    void on_kakkonen_pushButton_clicked();

    void on_kolomonen_pushButton_clicked();

    void on_enter_pushButton_clicked();

    void on_clear_pushButton_clicked();

    void on_nelonen_pushButton_clicked();

    void on_vitonen_pushButton_clicked();

    void on_kutonen_pushButton_clicked();

    void on_seiska_pushButton_clicked();

    void on_kasi_pushButton_clicked();

    void on_ysi_pushButton_clicked();

    void on_nolla_pushButton_clicked();

    void on_kerto_pushButton_clicked();

    void on_jako_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int num1;
    int num2;
    float result;
    int tila = 0;
};
#endif // MAINWINDOW_H
