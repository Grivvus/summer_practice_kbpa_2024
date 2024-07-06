#include "include/computeranswersgame.h"
#include "ui_computeranswersgame.h"

#include "include/gamelogic.h"

#include "QMessageBox"

ComputerAnswersGame::ComputerAnswersGame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ComputerAnswersGame)
{
    fillOutVector();
    ui->setupUi(this);
    this->prevNumber = -1;
    this->prevNumber = gameAlgorithm(this->prevNumber, 0, 0);
    ui->computerAnswer->setText(QString::number(this->prevNumber));
}

ComputerAnswersGame::~ComputerAnswersGame()
{
    delete ui;
}

void ComputerAnswersGame::on_sendAnswer_clicked()
{
    int numOfBulls;
    int numOfCows;
    numOfBulls = ui->numberOfBulls->text().toInt();
    numOfCows = ui->numberOfCows->text().toInt();
    if (numOfBulls == 4){
        QMessageBox::critical(this, "Win", "I win");
        delete this;
    }
    this->prevNumber = gameAlgorithm(this->prevNumber, numOfBulls, numOfCows);
    ui->computerAnswer->setText(QString::number(prevNumber));
}
