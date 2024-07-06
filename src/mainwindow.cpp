#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include "include/personanswersgame.h"
#include "include/computeranswersgame.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_userAnswersStartGame_clicked()
{
    PersonAnswersGame* instance = new PersonAnswersGame;

    instance->show();
}

void MainWindow::on_compAnswersStartGame_clicked()
{
    ComputerAnswersGame* instance = new ComputerAnswersGame;
    instance->show();
}
