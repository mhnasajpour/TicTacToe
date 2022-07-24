#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QDialog>

namespace Ui {
class GameHistory;
}

class GameHistory : public QDialog
{
    Q_OBJECT

public:
    explicit GameHistory(QString n1, QString n2, int row, QWidget *parent = nullptr);
    ~GameHistory();

private:
    Ui::GameHistory *ui;
    void check(int row);
    void showGameHistory(QPushButton*, int);
};

#endif // GAMEHISTORY_H
