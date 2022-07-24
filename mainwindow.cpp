#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "courtgame.h"
#include "getnames.h"
#include "historydialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/Logo/logo_black.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    GetNames *getName = new GetNames(this);
    getName->show();
    setHidden(true);
}


void MainWindow::on_pushButton_2_clicked()
{
    HistoryDialog *h = new HistoryDialog(this);
    h->show();
}

