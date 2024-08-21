#include <iostream>
#include <cstdlib >
#include <ctime>

int main() 
{
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1;
    int guess;
    bool guessed = false;

    while (!guessed) {
        std::cout << "Guess a number between 1 and 100: ";
        std::cin >> guess;
        if (guess == secretNumber) {
            std::cout << " Congratulations! You guessed the correct number.\n";
            guessed = true;
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Too high! Try again.\n";
        }
    }

    return 0;
}