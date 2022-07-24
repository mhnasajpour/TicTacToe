#include "historydialog.h"
#include "ui_historydialog.h"
#include <fstream>
#include <iostream>
#include "gamehistory.h"
using namespace std;

HistoryDialog::HistoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryDialog)
{
    ui->setupUi(this);
    ifstream file("History.txt");
    if(!file)
        ui->tableWidget->setDisabled(true);

    else{
        while(!file.eof()){
            string *name1, *name2, *winner;
            name1 = new string;
            name2 = new string;
            winner = new string;

            getline(file, *name1);
            if(*name1 == "")
                break;
            getline(file, *name2);
            getline(file, *winner);

            ui->tableWidget->insertRow(ui->tableWidget->rowCount());

            QTableWidgetItem *itemName1 = new QTableWidgetItem;
            itemName1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            itemName1->setFlags(itemName1->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));

            QTableWidgetItem *itemName2 = new QTableWidgetItem;
            itemName2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            itemName2->setFlags(itemName2->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));


            QTableWidgetItem *itemWinner = new QTableWidgetItem;
            itemWinner->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            itemWinner->setFlags(itemWinner->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));

            itemName1->setText(QString::fromStdString(*name1));
            itemName2->setText(QString::fromStdString(*name2));

            if(*winner == "2")
                itemWinner->setText("DRAW");

            else if(*winner == "1")
                itemWinner->setText(QString::fromStdString(*name2));

            else
                itemWinner->setText(QString::fromStdString(*name1));

            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, itemWinner);
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, itemName1);
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, itemName2);

            file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    connect(ui->tableWidget, SIGNAL(cellPressed(int, int)), this, SLOT(showGame(int)));
}

HistoryDialog::~HistoryDialog()
{
    delete ui;
}

void HistoryDialog::showGame(int row)
{
    GameHistory *h = new GameHistory(ui->tableWidget->item(row, 1)->text(), ui->tableWidget->item(row, 2)->text(), row, this);
    h->show();
}
