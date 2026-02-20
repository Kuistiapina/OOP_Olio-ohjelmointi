#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Placeholder koodilla:
    // QString placeholder_teksti = "0";
    // ui->lineEdit->setText(txt);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_countButton_clicked()
{
    // 1. Luetaan nykyinen luku
    QString luku = ui->lineEdit_laskuri->text();
    qDebug() << "Count-nappia painettu. Nykyinen luku merkkijonona: " << luku;

    // 2. Muutetaan merkkijono kokonaisluvuksi
    int num = luku.toInt();
    qDebug() << "Count-nappia painettu. Nykyinen luku kokonaislukuna: " << num;

    // 3. Lisätään lukuun yksi
    num = num+1;
    qDebug() << "Count-nappia painettu. Uusi luku kokonaislukuna on: " << num;

    // 4. Muutetaan kasvatettu luku takaisin tekstimuotoon ja viedään ulos
    QString uusiLuku = QString::number(num);
    ui->lineEdit_laskuri->setText(uusiLuku);
}


void MainWindow::on_resetButton_clicked()
{
    qDebug() << "Reset-nappia painettu";
    QString resetointi = "0";
    ui->lineEdit_laskuri->setText(resetointi);
}


void MainWindow::on_lineEdit_laskuri_textEdited(const QString &arg1)
{
    qDebug() << "Laskurin tulos muuttunut";

}

