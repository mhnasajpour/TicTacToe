#include "gamehistory.h"
#include "ui_gamehistory.h"
#include <fstream>
#include <iostream>
using namespace std;

GameHistory::GameHistory(QString n1, QString n2, int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameHistory)
{
    ui->setupUi(this);
    check(row);
    ui->label->setText(n1);
    ui->label_2->setText(n2);
}

GameHistory::~GameHistory()
{
    delete ui;
}

void GameHistory::check(int row){
    ifstream file("History.txt");
    for(int i = 0; i < 3 + (4 * row); i++)
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    int t;
    file >> t;
    showGameHistory(ui->pushButton, t);
    file >> t;
    showGameHistory(ui->pushButton_2, t);
    file >> t;
    showGameHistory(ui->pushButton_3, t);
    file >> t;
    showGameHistory(ui->pushButton_4, t);
    file >> t;
    showGameHistory(ui->pushButton_5, t);
    file >> t;
    showGameHistory(ui->pushButton_6, t);
    file >> t;
    showGameHistory(ui->pushButton_7, t);
    file >> t;
    showGameHistory(ui->pushButton_8, t);
    file >> t;
    showGameHistory(ui->pushButton_9, t);
    file.close();
}

void GameHistory::showGameHistory(QPushButton *n, int t)
{
    if(t == 1){
        QPixmap pixmap(":/shape/2.png");
        QIcon ButtonIcon(pixmap);
        n->setIcon(ButtonIcon);
        n->setIconSize(QSize(100,100));
    }
    else if(t == 2){
        QPixmap pixmap(":/shape/1.png");
        QIcon ButtonIcon(pixmap);
        n->setIcon(ButtonIcon);
        n->setIconSize(QSize(100,100));
    }
}
