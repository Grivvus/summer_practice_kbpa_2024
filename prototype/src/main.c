#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
global variables
*/
int isAnswerCorrect = 0;
int scoreCount = 0;
char hiddenNumber[4];
char hiddenCopy[4];
char answerNumber[4];
char answerCopy[4];
char allPossibleAnswers[4][5040];
char* greetingsText = "This is bulls and cows game, where you (or computer) should guess the number\nif you guess one right digit on right position, number of bulls will become 1\nif you guess one right digit but on wrond position, number of cows will become 1\nGood luck\n";
char* winText =  "congratulations, you found the correct answer in %d attempts\n";

/*
functions declaration
*/
int personAnswersStartGame();
void generateHiddenNumber();
void handleUserAnswer();
int* checkAnswer(char* hiddenNumber, char* answerNumber);
char* copy(char* source);
int computerAnswersStartGame();
char* algorithm(int numofbulls, int numofcows);
int* parseBullsAndCowsNumber();


int main(int argc, char* argv[]){
    srand(time(NULL));
    personAnswersStartGame();
    // computerAnswersStartGame();
    return 0;
}

int personAnswersStartGame(){
    int* numOfBullsAndCows;
    generateHiddenNumber();

    /*printf("%s\n", hiddenNumber);*/
    printf("%s", greetingsText);

    while (1){
        handleUserAnswer();
        scoreCount++;
        numOfBullsAndCows = checkAnswer(hiddenNumber, answerNumber);
        printf("You have %d bulls and %d cows\n", *numOfBullsAndCows, *(numOfBullsAndCows + 1));
        if (*numOfBullsAndCows == 4){
            free(numOfBullsAndCows);
            break;
        }
        free(numOfBullsAndCows);
    }
    printf(winText, scoreCount);

    return 0;
}

void generateHiddenNumber(){
    char digits[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    int cnt = 0;
    while (cnt < 4){
        int index = random() % 10;
        if (digits[index] != 'a'){
            hiddenNumber[cnt] = digits[index];
            cnt++;
            digits[index] = 'a';
        }
    }
}

void handleUserAnswer(){
    scanf("%s", answerNumber);
}

int* checkAnswer(char* hiddenNumber, char* answerNumber){
    int bulls = 0;
    int cows = 0;
    char* hiddenCopy = copy(hiddenNumber);
    int* result = (int*)malloc(sizeof(int) * 2);

    for (int i = 0; i < 4; i++){
        if (answerNumber[i] == hiddenCopy[i]){
            hiddenCopy[i] = 'a';
            bulls++;
        }
    }

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (answerNumber[i] == hiddenCopy[j]){
                hiddenCopy[j] = 'a';
                cows++;
            }
        }
    }
    free(hiddenCopy);

    *result = bulls;
    *(result + 1) = cows;

    return result;
}

char* copy(char* source){
    char* result = (char*)malloc(sizeof(char) * 4);
    for (int i = 0; i < 4; i++){
        *(result + i) = source[i];
    }
    return result;
}

int computerAnswersStartGame(){
    int cnt = 0;
    printf("%s", "In this version computer should find your hidden number\nCome up with a number and remember it\nthen check the number, that computer gives you and write your hint in format:\nnum1 num2\nwhere num1 is number of bulls and num2 is number of cows\n");
    printf("%s\n", algorithm(0, 0));
    int* bullsAndCows = parseBullsAndCowsNumber();
    while (*bullsAndCows != 4){
        printf("%d %d\n", *bullsAndCows, *(bullsAndCows + 1));
        if (*bullsAndCows != -1){
            cnt++;
            char* res = algorithm(*bullsAndCows, *(bullsAndCows + 1));
            printf("%s\n", res);
        }
        else{
            printf("%s", "number of bulls and cows is incorrect\n");
        }
        free(bullsAndCows);
        bullsAndCows = parseBullsAndCowsNumber();
    }
    printf("The algorithm guessed the unswer in %d attempts\n", cnt);
    return 0;
}

char* algorithm(int numofbulls, int numofcows){
    return "4444";
}

int* parseBullsAndCowsNumber(){
    int* bullsAndCows = (int*)malloc(sizeof(int) * 2);
    scanf("%d %d", bullsAndCows, bullsAndCows + 1);
    if (*bullsAndCows + *(bullsAndCows + 1) > 4){
        printf("ты мне тут карты то не путай\n");
        *bullsAndCows = -1;
        *(bullsAndCows + 1) = -1;
    }
    return bullsAndCows;
}

