#include "include/personanswersgame.h"
#include "ui_personanswersgame.h"

#include <iostream>

#include "include/gamelogic.h"

PersonAnswersGame::PersonAnswersGame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PersonAnswersGame)
{
    ui->setupUi(this);
    this->randomNumber = generateRandomNumber();
    std::cout <<  this->randomNumber << "\n";
}

PersonAnswersGame::~PersonAnswersGame()
{
    delete ui;
}

void PersonAnswersGame::on_sendAnswer_clicked()
{
    std::cout << "send answer click\n";
    int answer = ui->answer->text().toInt();
    if (!isNumberCorrect(answer)){
        QMessageBox::critical(this, "Error", "Incorrect number");
    } else {
        std::pair<int, int> bullsAndCows = countBullsAndCows(this->randomNumber, answer);
        if (bullsAndCows.first == 4) {
            QMessageBox::critical(this, "Win", "You win");
            this->close();
        } else {
            ui->numberOfBulls->setText(QString::number(bullsAndCows.first));
            ui->numberOfCows->setText(QString::number(bullsAndCows.second));
        }
    }

}
