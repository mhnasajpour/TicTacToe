#ifndef DRAWDIALOG_H
#define DRAWDIALOG_H

#include <QDialog>

namespace Ui {
class DrawDialog;
}

class DrawDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DrawDialog(QWidget *parent = nullptr);
    ~DrawDialog();

private:
    Ui::DrawDialog *ui;
};

#endif // DRAWDIALOG_H
