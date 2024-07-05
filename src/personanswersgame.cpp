#include "include/personanswersgame.h"
#include "ui_personanswersgame.h"

#include "include/gamelogic.h"

PersonAnswersGame::PersonAnswersGame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PersonAnswersGame)
{
    ui->setupUi(this);
}

PersonAnswersGame::~PersonAnswersGame()
{
    delete ui;
}

void PersonAnswersGame::on_sendAnswer_clicked()
{
    int answer = ui->answer->text().toInt();
    std::pair<int, int> bullsAndCows = countBullsAndCows(randomNumber, answer);
    ui->numberOfBulls->setText(QString::number(bullsAndCows.first));
    ui->numberOfCows->setText(QString::number(bullsAndCows.second));
}
