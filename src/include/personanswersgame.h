#ifndef PERSONANSWERSGAME_H
#define PERSONANSWERSGAME_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class PersonAnswersGame;
}

class PersonAnswersGame : public QWidget
{
    Q_OBJECT

public:
    explicit PersonAnswersGame(QWidget *parent = nullptr);
    ~PersonAnswersGame();

private slots:

    void on_sendAnswer_clicked();

private:
    Ui::PersonAnswersGame *ui;
};

#endif // PERSONANSWERSGAME_H
