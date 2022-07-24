#ifndef COURTGAME_H
#define COURTGAME_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class CourtGame;
}

class CourtGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit CourtGame(int, int, QWidget *parent = nullptr);
    ~CourtGame();

private:
    Ui::CourtGame *ui;
    bool turn;
    int *isExist;
    void isCheck();
    int score1;
    int score2;
    bool isFinish;

public slots:
    void getLabel1(QString);
    void getLabel2(QString);
    void getPbn(QPushButton *);

signals:
    void pbn(QPushButton *);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_actionNew_triggered();
    void on_actionReset_triggered();
    void on_actionMain_menu_triggered();
    void on_actionExit_triggered();
    void on_actionHistory_triggered();
    void on_pushButton_12_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
};

#endif // COURTGAME_H
