#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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

public slots:

    void timeout(); // Qtimerin timeout-signaalille

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_timeButton_1_clicked();

    void on_timeButton_2_clicked();

    void on_swapPlayer_1_clicked();

    void on_swapPlayer_2_clicked();

private:
    Ui::MainWindow *ui;
    int player1Time = 0;        // Pelaajien jäljellä oleva aika sekunteina
    int player2Time = 0;
    int gameTime = 0;           // Peliaika
    QTimer *timer;              // Ajastin, joka vähentää aikaa
    bool player1Turn = true;    // Tarkistus kumman vuoro on meneillään
    void updateProgressBar();
    void setGameInfoText(const QString &infoTeksti);

};
#endif // MAINWINDOW_H
