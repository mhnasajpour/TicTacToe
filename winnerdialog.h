#ifndef WINNERDIALOG_H
#define WINNERDIALOG_H

#include <QDialog>

namespace Ui {
class WinnerDialog;
}

class WinnerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinnerDialog(QString name, QWidget *parent = nullptr);
    ~WinnerDialog();

private:
    Ui::WinnerDialog *ui;
};

#endif // WINNERDIALOG_H
