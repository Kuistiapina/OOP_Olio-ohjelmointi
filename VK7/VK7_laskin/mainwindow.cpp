#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_plussa_pushButton_clicked()
{
    // Suoritetaan laskutoimitus vasta kun molemmat luvut ovat sy
    if (tila == 2){
    qDebug() << "Laskutoimitus plus sallittu";
    QString luku1 = ui->num1_lineEdit->text();
    num1 = luku1.toInt();

    QString luku2 = ui->num2_lineEdit->text();
    num2 = luku2.toInt();

    result = num1 + num2;
    QString tulos = QString::number(result);
    ui->tulos_lineEdit->setText(tulos);

    qDebug() << num1 << " + " << num2 << " = " << result;
    }
    // Palataan alkutilaan eli syötetään taas kenttään 1
    tila = 0;
    qDebug() << "Nykyinen tila: " << tila;
}

void MainWindow::on_miinus_pushButton_clicked()
{
    if (tila == 2){
    qDebug() << "Laskutoimitus miinus sallittu";
    QString luku1 = ui->num1_lineEdit->text();
    num1 = luku1.toInt();

    QString luku2 = ui->num2_lineEdit->text();
    num2 = luku2.toInt();

    result = num1 - num2;
    QString tulos = QString::number(result);
    ui->tulos_lineEdit->setText(tulos);

    qDebug() << num1 << " - " << num2 << " = " << result;
    }
    tila = 0;
    qDebug() << "Nykyinen tila: " << tila;
}

void MainWindow::on_kerto_pushButton_clicked()
{
    if (tila == 2){
        qDebug() << "Laskutoimitus kerto sallittu";
        QString luku1 = ui->num1_lineEdit->text();
        num1 = luku1.toInt();

        QString luku2 = ui->num2_lineEdit->text();
        num2 = luku2.toInt();

        result = num1 * num2;
        QString tulos = QString::number(result);
        ui->tulos_lineEdit->setText(tulos);

        qDebug() << num1 << " * " << num2 << " = " << result;
    }
    tila = 0;
    qDebug() << "Nykyinen tila: " << tila;
}

void MainWindow::on_jako_pushButton_clicked()
{
    if (tila == 2){
        qDebug() << "Laskutoimitus jako sallittu";
        QString luku1 = ui->num1_lineEdit->text();
        num1 = luku1.toInt();

        QString luku2 = ui->num2_lineEdit->text();
        num2 = luku2.toInt();

        result = num1 / num2;
        QString tulos = QString::number(result);
        ui->tulos_lineEdit->setText(tulos);

        qDebug() << num1 << " / " << num2 << " = " << result;
    }
    tila = 0;
    qDebug() << "Nykyinen tila: " << tila;
}

void MainWindow::on_ykkonen_pushButton_clicked()
{
    setEditNum(1);
}


void MainWindow::on_kakkonen_pushButton_clicked()
{
    setEditNum(2);
}


void MainWindow::on_kolomonen_pushButton_clicked()
{
    setEditNum(3);
}

void MainWindow::on_nelonen_pushButton_clicked()
{
    setEditNum(4);
}

void MainWindow::on_vitonen_pushButton_clicked()
{
    setEditNum(5);
}

void MainWindow::on_kutonen_pushButton_clicked()
{
    setEditNum(6);
}

void MainWindow::on_seiska_pushButton_clicked()
{
    setEditNum(7);
}
void MainWindow::on_kasi_pushButton_clicked()
{
    setEditNum(8);
}

void MainWindow::on_ysi_pushButton_clicked()
{
    setEditNum(9);
}

void MainWindow::on_nolla_pushButton_clicked()
{
    setEditNum(0);
}


void MainWindow::setEditNum(int num)
{
    QString nykyinenLuku;
    if (tila == 0){
        // Tila 0: Kirjoitetaan ensimmäiseen kenttään
        nykyinenLuku = ui->num1_lineEdit->text();
        nykyinenLuku = nykyinenLuku + QString::number(num);
        ui->num1_lineEdit->setText(nykyinenLuku);
        qDebug() << "Nykyinen tila: " << tila;
    }else if (tila == 1){
        //Tila 1: Kirjoitetaan toiseen kenttään
        nykyinenLuku = ui->num2_lineEdit->text();
        nykyinenLuku = nykyinenLuku + QString::number(num);
        ui->num2_lineEdit->setText(nykyinenLuku);
        qDebug() << "Nykyinen tila: " << tila;
    }else if (tila == 2){
        // Tila 2: Suoritetaan laskutoimitus
        qDebug() << "Et voi muokata numeroita juuri nyt, suorita laskutoimitus!";
    }

}

void MainWindow::on_enter_pushButton_clicked()
{
    qDebug() << "Nykyinen tila: " << tila;
    // Tilasta 0 tilaan 1
    if (tila == 0){
        tila = 1;
    // Tilasta 1 tilaan 2
    }else if ( tila == 1){
        tila = 2;
    }
    qDebug() << "Uusi tila: " << tila;
}


void MainWindow::on_clear_pushButton_clicked()
{
    ui->num1_lineEdit->clear();
    ui->num2_lineEdit->clear();
    ui->tulos_lineEdit->clear();
    tila = 0;
}

