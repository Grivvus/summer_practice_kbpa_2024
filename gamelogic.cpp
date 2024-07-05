#include "gamelogic.h"

std::vector<int> possibleNumbers;
int randomNumber;

void fillOutVector(){
    for (int i = 0; i <= 9999; i++){
        if (isNumberCorrect(i)){
            possibleNumbers.push_back(i);
        }
    }
}

bool isNumberCorrect(int number){
    if (number < 1000){
        return false;
    }
    if (number > 9999){
        return false;
    }
    std::vector<int> digits;
    for (int i = 0; i < 4; i++){
        digits.push_back((number / (int)(pow(10, i))) % 10);
    }
    for (int num : digits){
        if (std::count(digits.begin(), digits.end(), num) > 1){
            return false;
        }
    }
    return true;
}

int gameAlgorithm(int prevNumber, int numOfBulls, int numOfCows){
    if (prevNumber == -1){
        return possibleNumbers.back();
    }
    removeImpossibelNumbers(prevNumber, numOfBulls, numOfCows);
    return possibleNumbers[rand() % possibleNumbers.size()];
}

void removeImpossibelNumbers(int prevNumber, int numOfBulls, int numOfCows){

}


std::pair<int, int> countBullsAndCows(int num1, int num2){
    int numberOfCows = 0;
    int numberOfBulls = 0;
    std::string num1AsString = std::to_string(num1);
    std::string num2AsString = std::to_string(num2);
    for (size_t i = 0; i < num1AsString.length(); ++i) {
        if (num1AsString[i] == num2AsString[i]) {
            numberOfBulls++;
        } else {
            if (num2AsString.find(num1AsString[i]) != std::string::npos) {
                numberOfCows++;
            }
        }
    }
    return std::pair<int, int>(numberOfBulls, numberOfCows);
}

int generateRandomNumber(void){
    std::vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::random_device rd;
    std::mt19937 g(rd());
    while (digits[0] == 0){
        std::shuffle(digits.begin(), digits.end(), g);
    }

    int res = 1000 * digits[0] + 100 * digits[1] + 10 * digits[2] + digits[3];
    return res;
}


/*int main(int argc, char** argv){*/
/*    fillOutVector();*/
/*    srand(time(NULL));*/
/*    std::cout << generateRandomNumber() << "\n" << generateRandomNumber() << "\n";*/
/*    std::cout << generateRandomNumber() << "\n" << generateRandomNumber() << "\n";*/
/*    std::cout << generateRandomNumber() << "\n" << generateRandomNumber() << "\n";*/
/*    std::cout << generateRandomNumber() << "\n" << generateRandomNumber() << "\n";*/
/*    return 0;*/
/*}*/
