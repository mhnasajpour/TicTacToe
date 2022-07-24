#include "courtgame.h"
#include "ui_courtgame.h"
#include <fstream>
#include <iostream>
#include "winnerdialog.h"
#include "drawdialog.h"
#include "getnames.h"
#include "mainwindow.h"
#include "historydialog.h"
using namespace std;

CourtGame::CourtGame(int _score1, int _score2, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CourtGame)
{
    isFinish = false;
    score1 = _score1;
    score2 = _score2;
    turn = 0;
    isExist = new int[9];

    for(int i = 0; i < 9; i++)
        isExist[i] = 0;

    ui->setupUi(this);
    ui->label_3->setText(QString::number(score1));
    ui->label_4->setText(QString::number(score2));

    ui->pushButton_11->setHidden(true);
    ui->pushButton_12->setHidden(true);
    ui->pushButton_13->setHidden(true);
    ui->pushButton_14->setHidden(true);
    ui->pushButton_15->setHidden(true);
    connect(this, SIGNAL(pbn(QPushButton*)), this, SLOT(getPbn(QPushButton*)));

}

CourtGame::~CourtGame()
{
    delete ui;
}

void CourtGame::getLabel1(QString str)
{
    ui->label->setText(str);
}

void CourtGame::getLabel2(QString str)
{
    ui->label_2->setText(str);
}

void CourtGame::getPbn(QPushButton *n){      
    if(turn == 0){
        QPixmap pixmap(":/shape/2.png");
        QIcon ButtonIcon(pixmap);
        n->setIcon(ButtonIcon);
        n->setIconSize(QSize(100,100));
        turn = 1;
        ui->pushButton_11->setHidden(false);
        ui->pushButton_10->setHidden(true);
    }

    else{
        QPixmap pixmap(":/shape/1.png");
        QIcon ButtonIcon(pixmap);
        n->setIcon(ButtonIcon);
        n->setIconSize(QSize(100,100));
        turn = 0;
        ui->pushButton_11->setHidden(true);
        ui->pushButton_10->setHidden(false);
    }
    isCheck();
}

/*
    0   1   2
    3   4   5
    6   7   8
*/

void CourtGame::isCheck(){
    bool b = false;

    if((isExist[0] == 1 && isExist[1] == 1 && isExist[2] == 1) || (isExist[0] == 2 && isExist[1] == 2 && isExist[2] == 2)){
        ui->pushButton->setDisabled(true);
        ui->pushButton_2->setDisabled(true);
        ui->pushButton_3->setDisabled(true);
        b = true;
    }
    if((isExist[3] == 1 && isExist[4] == 1 && isExist[5] == 1) || (isExist[3] == 2 && isExist[4] == 2 && isExist[5] == 2)){
        ui->pushButton_4->setDisabled(true);
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_6->setDisabled(true);
        b = true;
    }
    if((isExist[6] == 1 && isExist[7] == 1 && isExist[8] == 1) || (isExist[6] == 2 && isExist[7] == 2 && isExist[8] == 2)){
        ui->pushButton_7->setDisabled(true);
        ui->pushButton_8->setDisabled(true);
        ui->pushButton_9->setDisabled(true);
        b = true;
    }

    if((isExist[0] == 1 && isExist[3] == 1 && isExist[6] == 1) || (isExist[0] == 2 && isExist[3] == 2 && isExist[6] == 2)){
        ui->pushButton->setDisabled(true);
        ui->pushButton_4->setDisabled(true);
        ui->pushButton_7->setDisabled(true);
        b = true;
    }
    if((isExist[1] == 1 && isExist[4] == 1 && isExist[7] == 1) || (isExist[1] == 2 && isExist[4] == 2 && isExist[7] == 2)){
        ui->pushButton_2->setDisabled(true);
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_8->setDisabled(true);
        b = true;
    }
    if((isExist[2] == 1 && isExist[5] == 1 && isExist[8] == 1) || (isExist[2] == 2 && isExist[5] == 2 && isExist[8] == 2)){
        ui->pushButton_3->setDisabled(true);
        ui->pushButton_6->setDisabled(true);
        ui->pushButton_9->setDisabled(true);
        b = true;
    }

    if((isExist[0] == 1 && isExist[4] == 1 && isExist[8] == 1) || (isExist[0] == 2 && isExist[4] == 2 && isExist[8] == 2)){
        ui->pushButton->setDisabled(true);
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_9->setDisabled(true);
        b = true;
    }
    if((isExist[2] == 1 && isExist[4] == 1 && isExist[6] == 1) || (isExist[2] == 2 && isExist[4] == 2 && isExist[6] == 2)){
        ui->pushButton_3->setDisabled(true);
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_7->setDisabled(true);
        b = true;
    }
    if(b){
        ofstream file;
        file.open("History.txt", ios::app);
        file << ui->label->text().toStdString() << '\n' << ui->label_2->text().toStdString() << '\n' << !turn << endl;
        for(int i = 0; i < 9; i++)
            file << isExist[i] << ' ';

        file << endl;
        file.close();

        ui->pushButton_10->setHidden(false);
        ui->pushButton_11->setHidden(false);
        ui->pushButton_12->setHidden(false);
        ui->pushButton_13->setHidden(false);
        ui->pushButton_14->setHidden(false);
        ui->pushButton_15->setHidden(false);
        isFinish = true;

        if(!turn == 0){
            WinnerDialog *winner = new WinnerDialog(ui->label->text(), this);
            ui->label_3->setText(QString::number(++score1));
            winner->show();
        }
        else{
            WinnerDialog *winner = new WinnerDialog(ui->label_2->text(), this);
            ui->label_4->setText(QString::number(++score2));
            winner->show();
        }
    }
    for(int i = 0; i < 9; i++){
        if(!isExist[i])
            break;
        if(i == 8){
            ofstream file;
            file.open("History.txt", ios::app);
            file << ui->label->text().toStdString() << '\n' << ui->label_2->text().toStdString() << '\n' << 2 << endl;
            for(int i = 0; i < 9; i++)
                file << isExist[i] << ' ';

            file << endl;
            file.close();

            ui->pushButton_10->setHidden(false);
            ui->pushButton_11->setHidden(false);
            ui->pushButton_12->setHidden(false);
            ui->pushButton_13->setHidden(false);
            ui->pushButton_14->setHidden(false);
            ui->pushButton_15->setHidden(false);
            isFinish = true;

            DrawDialog *draw = new DrawDialog(this);
            draw->show();
        }
    }
}

void CourtGame::on_pushButton_clicked()
{
    if(isExist[0] == 0 && isFinish == false){
        isExist[0] = turn + 1;
        emit pbn(ui->pushButton);
    }
}

void CourtGame::on_pushButton_2_clicked()
{
    if(isExist[1] == 0 && isFinish == false){
        isExist[1] = turn + 1;
        emit pbn(ui->pushButton_2);
    }
}

void CourtGame::on_pushButton_3_clicked()
{
    if(isExist[2] == 0 && isFinish == false){
        isExist[2] = turn + 1;
        emit pbn(ui->pushButton_3);
    }
}

void CourtGame::on_pushButton_4_clicked()
{
    if(isExist[3] == 0 && isFinish == false){
        isExist[3] = turn + 1;
        emit pbn(ui->pushButton_4);
    }
}

void CourtGame::on_pushButton_5_clicked()
{
    if(isExist[4] == 0 && isFinish == false){
        isExist[4] = turn + 1;
        emit pbn(ui->pushButton_5);
    }
}

void CourtGame::on_pushButton_6_clicked()
{
    if(isExist[5] == 0 && isFinish == false){
        isExist[5] = turn + 1;
        emit pbn(ui->pushButton_6);
    }
}

void CourtGame::on_pushButton_7_clicked()
{
    if(isExist[6] == 0 && isFinish == false){
        isExist[6] = turn + 1;
        emit pbn(ui->pushButton_7);
    }
}

void CourtGame::on_pushButton_8_clicked()
{
    if(isExist[7] == 0 && isFinish == false){
        isExist[7] = turn + 1;
        emit pbn(ui->pushButton_8);
    }
}

void CourtGame::on_pushButton_9_clicked()
{
    if(isExist[8] == 0 && isFinish == false){
        isExist[8] = turn + 1;
        emit pbn(ui->pushButton_9);
    }
}


void CourtGame::on_actionNew_triggered()
{
    GetNames *getName = new GetNames(this);
    getName->show();
    setHidden(true);
}


void CourtGame::on_actionReset_triggered()
{
    CourtGame *court = new CourtGame(score1, score2);
    court->getLabel1(ui->label->text());
    court->getLabel2(ui->label_2->text());
    court->show();
    close();
}


void CourtGame::on_actionMain_menu_triggered()
{
    MainWindow *main = new MainWindow;
    main->show();
    close();
}


void CourtGame::on_actionExit_triggered()
{
    close();
}


void CourtGame::on_actionHistory_triggered()
{
    HistoryDialog *h = new HistoryDialog(this);
    h->show();
}


void CourtGame::on_pushButton_12_clicked()
{
    GetNames *getName = new GetNames(this);
    getName->show();
    setHidden(true);
}


void CourtGame::on_pushButton_15_clicked()
{
    HistoryDialog *h = new HistoryDialog(this);
    h->show();
}


void CourtGame::on_pushButton_13_clicked()
{
    close();
}


void CourtGame::on_pushButton_14_clicked()
{
    CourtGame *court = new CourtGame(score1, score2);
    court->getLabel1(ui->label->text());
    court->getLabel2(ui->label_2->text());
    court->show();
    close();
}

