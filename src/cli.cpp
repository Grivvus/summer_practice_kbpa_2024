#include <iostream>

#include "include/cli.h"
#include "include/gamelogic.h"

int hiddenNumber;

int main(int argc, char** argv){
    if (argc == 1){
        std::cout << "too few arguments\n";
        exit(1);
    }
    if (std::string(argv[1]) == "-a" || std::string(argv[1]) == "--answer"){
        personAnswersGameCLI();
    }
    else if (std::string(argv[1]) == "-s" || std::string(argv[1]) == "--ask"){
        computerAnswersGameCLI();
    }
    else if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help"){
        printHelpText();
    }
    else {
        std::cout << "unknown command\n";
        printHelpText();
        exit(1);
    }
    return 0;
}

int printHelpText(){
    std::cout << "-a | --answer : you start game, where you trying to find hidden number\n";
    std::cout << "-s | --ask : you start game, where computer trying to find your hidden number\n";
    std::cout << "-h | --help : print this help text\n";
    return 0;
}

int personAnswersGameCLI(){
    int numberOfAttempts = 0;
    hiddenNumber = generateRandomNumber();
    std::pair<int, int> bullsAndCows = std::pair(0, 0);

    while (bullsAndCows.first != 4){
        int expectedNumber = handleUserInput();
        if (!isNumberCorrect(expectedNumber)){
            std::cout << "Number is incorrect\n";
            continue;
        }
        numberOfAttempts++;
        bullsAndCows = countBullsAndCows(hiddenNumber, expectedNumber);
        printAnswerToUser(bullsAndCows);
    }
    printUserWinText(numberOfAttempts);
    return 0;
}

int handleUserInput(){
    int expectedNumber;
    std::cin >> expectedNumber;
    return expectedNumber;
}

int printAnswerToUser(std::pair<int, int> bullsAndCows){
    std::cout << "You have " << bullsAndCows.first << " bulls ";
    std::cout << "and " << bullsAndCows.second << " cows\n";
    return 0;
}

int printUserWinText(int numberOfAttempts){
    std::cout << "Congatulations you won in " << numberOfAttempts << " attempts\n";
    return 0;
}

int computerAnswersGameCLI(){
    int numberOfAttempts = 0;
    fillOutVector();
    std::pair<int, int> bullsAndCows = std::pair(0, 0);
    int prevNumber = -1;
    while (bullsAndCows.first != 4){
        prevNumber = gameAlgorithm(prevNumber, bullsAndCows.first, bullsAndCows.second);
        printExpected(prevNumber);
        bullsAndCows = getBullsAndCows();
        numberOfAttempts++;
    }
    printCompWinText(numberOfAttempts);
    return 0;
}

int printExpected(int number){
    std::cout << number << std::endl;
    return 0;
}

std::pair<int, int> getBullsAndCows(){
    int bulls;
    int cows;
    std::cin >> bulls >> cows;
    return std::pair(bulls, cows);
}

int printCompWinText(int numberOfAttempts){
    std::cout << "I found your number in " << numberOfAttempts << " attempts\n";
    return 0;
}
