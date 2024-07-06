#ifndef COMPUTERANSWERSGAME_H
#define COMPUTERANSWERSGAME_H

#include <QWidget>

namespace Ui {
class ComputerAnswersGame;
}

class ComputerAnswersGame : public QWidget
{
    Q_OBJECT

public:
    explicit ComputerAnswersGame(QWidget *parent = nullptr);
    ~ComputerAnswersGame();

private slots:
    void on_sendAnswer_clicked();

private:
    Ui::ComputerAnswersGame *ui;
};

#endif // COMPUTERANSWERSGAME_H
