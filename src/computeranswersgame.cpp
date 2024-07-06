#include "include/computeranswersgame.h"
#include "ui_computeranswersgame.h"

ComputerAnswersGame::ComputerAnswersGame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ComputerAnswersGame)
{
    ui->setupUi(this);
}

ComputerAnswersGame::~ComputerAnswersGame()
{
    delete ui;
}

void ComputerAnswersGame::on_sendAnswer_clicked()
{

}
