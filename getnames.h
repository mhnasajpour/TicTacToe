#ifndef GETNAMES_H
#define GETNAMES_H

#include <QDialog>

namespace Ui {
class GetNames;
}

class GetNames : public QDialog
{
    Q_OBJECT

public:
    explicit GetNames(QWidget *parent = nullptr);
    ~GetNames();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::GetNames *ui;

signals:
    void name1(QString);
    void name2(QString);
};

#endif // GETNAMES_H
