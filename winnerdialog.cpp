#include "winnerdialog.h"
#include "ui_winnerdialog.h"

WinnerDialog::WinnerDialog(QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinnerDialog)
{
    setWindowTitle(name);
    ui->setupUi(this);
    ui->label_2->setText(name);
}

WinnerDialog::~WinnerDialog()
{
    delete ui;
}
