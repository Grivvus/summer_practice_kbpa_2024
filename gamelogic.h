#include <algorithm>
#include <math.h>
#include <string>
#include <utility>
#include <vector>
#include <random>

void fillOutVector();
bool isNumberCorrect(int number);
void removeImpossibelNumbers(int prevNumber, int numOfBulls, int numOfCows);
void removeAllContains(int number);
std::pair<int, int> countBullsAndCows(int num1, int num2);
int generateRandomNumber(void);

/*gloabal variables*/
extern int randomNumber;
extern std::vector<int> possibleNumbers;
