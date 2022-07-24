#include "getnames.h"
#include "ui_getnames.h"
#include "courtgame.h"
#include "mainwindow.h"

GetNames::GetNames(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetNames)
{
    ui->setupUi(this);
}

GetNames::~GetNames()
{
    delete ui;
}

void GetNames::on_buttonBox_accepted()
{
    CourtGame *court = new CourtGame(0, 0, this);
    court->getLabel1(ui->lineEdit->text());
    court->getLabel2(ui->lineEdit_2->text());
    court->show();
}


void GetNames::on_buttonBox_rejected()
{
    MainWindow *main = new MainWindow;
    main->show();
    close();
}

