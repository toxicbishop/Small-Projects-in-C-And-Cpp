#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed for random number generation
    int guess = 0; // Random number between 1 and 100
    int tries = 0;
    int min = 1;
    int max = 100;
    int answer = (std::rand() % (max - min + 1)) + min; // Random number to be guessed
    
    std::cout << "***Welcome to the Number Guessing Game***\n";
    std::cout << "I have selected a number between " << min << " and " << max << ". Can you guess it?\n";
    
    // Loop until the user guesses the correct number
    do {
        std::cout << "Guess a number between " << min << " and " << max << ": ";
        
        if (!(std::cin >> guess)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n'); 
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        tries++;
        
        if (guess < answer) {
            std::cout << "Too low! Try again.\n";
        } 
        else if (guess > answer){
            std::cout << "Too high! Try again.\n";
        }
        else {
            std::cout << "Congratulations! You've guessed the correct number!\n";
        }
    } while (guess != answer);
    
    std::cout << "The answer is " << answer << "\n";
    std::cout << "It took you " << tries << " tries\n";
    std::cout << "Thank you for playing the Number Guessing Game!\n";

    return 0;
}