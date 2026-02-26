#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &MainWindow::timeout);

    // Aloitustila
    gameTime = 0;
    player1Time = 0;
    player2Time = 0;
    player1Turn = true;
    setGameInfoText("VALITSE AIKA JA ALOITA PELI!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{

    if (timer->isActive()) {
        setGameInfoText("PELI ON JO KÄYNNISSÄ!");
        return;
    }

    if(gameTime == 0){
        setGameInfoText("VALITSE ENSIN PELIAIKA!");
        return;
    }

    player1Turn = true;
    timer->start();
    setGameInfoText("PELAAJAN 1 VUORO!");
}


void MainWindow::on_stopButton_clicked()
{
    timer->stop();
    setGameInfoText("PELI LOPETETTU! ALOITA UUSI PELI VALITSEMALLA AIKA");
    ui->startButton->setEnabled(false);
}


void MainWindow::on_timeButton_1_clicked()
{

    if (timer->isActive()) {
        setGameInfoText("ET VOI VAIHTAA AIKAA KESKEN PELIN!");
        return;
    }

    gameTime = 2 * 60;
    player1Time = gameTime;
    player2Time = gameTime;
    updateProgressBar();
    setGameInfoText("AIKA VALITTU, PAINA 'ALOITA PELI'!");
    ui->startButton->setEnabled(true);

}


void MainWindow::on_timeButton_2_clicked()
{
    if (timer->isActive()) {
        setGameInfoText("ET VOI VAIHTAA AIKAA KESKEN PELIN!");
        return;
    }
    gameTime = 5 * 60;
    player1Time = gameTime;
    player2Time = gameTime;
    updateProgressBar();
    setGameInfoText("AIKA VALITTU, PAINA 'ALOITA PELI'!");
    ui->startButton->setEnabled(true);
}


void MainWindow::on_swapPlayer_1_clicked()
{
    if(player1Turn){
        player1Turn = false;
        setGameInfoText("PELAAJAN 2 VUORO!");
        ui->swapPlayer_1->setEnabled(false);
        ui->swapPlayer_2->setEnabled(true);
    }
}


void MainWindow::on_swapPlayer_2_clicked()
{
    if(!player1Turn){
        player1Turn = true;
        setGameInfoText("PELAAJAN 1 VUORO!");
        ui->swapPlayer_1->setEnabled(true);
        ui->swapPlayer_2->setEnabled(false);
    }
}

void MainWindow::timeout()
{
    if(player1Turn){
        player1Time--;
    }else{
        player2Time--;
    }

    updateProgressBar();

    if(player1Time <= 0){
        timer->stop();
        setGameInfoText("PELAAJAN 1 AIKA LOPPUI ELI PELAAJA 2 VOITTI JA PELI PÄÄTTYI! ALOITA UUSI PELI VALITSEMALLA AIKA");

        // Estetään start-nappi ennen uutta ajanvalintaa
        ui->startButton->setEnabled(false);

        // Ajanvalinta takaisin päälle
        ui->timeButton_1->setEnabled(true);
        ui->timeButton_2->setEnabled(true);
        return;

    }
    if(player2Time <= 0){
        timer->stop();
        setGameInfoText("PELAAJAN 2 AIKA LOPPUI ELI PELAAJA 1 VOITTI JA PELI PÄÄTTYI! ALOITA UUSI PELI VALITSEMALLA AIKA");

        // Estetään start-nappi ennen uutta ajanvalintaa
        ui->startButton->setEnabled(false);

        // Ajanvalinta takaisin päälle
        ui->timeButton_1->setEnabled(true);
        ui->timeButton_2->setEnabled(true);
        return;

    }
}

void MainWindow::updateProgressBar()
{
    if(gameTime == 0){
        return;
    }
    int pelaaja1 = (player1Time * 100) / gameTime;
    int pelaaja2 = (player2Time * 100) / gameTime;

    ui->progressBarPlayer_1->setValue(pelaaja1);
    ui->progressBarPlayer_2->setValue(pelaaja2);
}

void MainWindow::setGameInfoText(const QString &infoTeksti)
{
    ui->infoTeksti->setText(infoTeksti);
}
