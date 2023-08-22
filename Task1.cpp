// TASK 1:- Create a program that generates a random number and asks the
//user to guess it. Provide feedback on whether the guess is too
//high or too low until the user guesses the correct number.

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
 {
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    
    int secretNumber = std::rand() % 100 + 1;
    int userGuess;
    int numAttempts = 0;

    std::cout << "Welcome to the Number Guessing Game " << std::endl;
    std::cout << "I have selected a number between 1 and 100. Try to guess it." << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        numAttempts++;

        if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " in " << numAttempts << " attempts." << std::endl;
        }
    } while (userGuess != secretNumber);

    return 0;
}
