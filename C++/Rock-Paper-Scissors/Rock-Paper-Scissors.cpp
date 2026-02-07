#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <windows.h> // For Sleep

int getComputer_Choice();
int getUser_Choice();
void CheckWinner(int userchoice, int computerchoice);
std::string choiceToString(int choice);

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number generation
    std::cout << "***Welcome to Rock-Paper-Scissors Game***\n";

    int userchoice = getUser_Choice();
    int computerchoice = getComputer_Choice();
    
    std::cout << "You chose: " << choiceToString(userchoice) << "\n";
    std::cout << "Computer chose: " << choiceToString(computerchoice) << "\n";

    CheckWinner(userchoice, computerchoice);

    return 0;
}

int getComputer_Choice() {
    int min = 1;
    int max = 3;
    int computerchoice = (std::rand() % (max - min + 1)) + min; // Random number between 1 and 3
    std::cout << "Computer is making a choice...\n";
    Sleep(1000); // Simulate thinking time (milliseconds)
    std::cout << "Computer has made its choice.\n";
    Sleep(500); // Brief pause before revealing choice
    return computerchoice;
}

int getUser_Choice() {
    int userchoice;
    do {
        std::cout << "Enter your choice\n";
        std::cout << "(1 for Rock, 2 for Paper, 3 for Scissors): ";
        
        if (!(std::cin >> userchoice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear invalid input
            userchoice = 0;
        }
        
        if (userchoice < 1 || userchoice > 3) {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (userchoice < 1 || userchoice > 3);
    return userchoice;
}

void CheckWinner(int userchoice, int computerchoice) {
    if (userchoice == computerchoice) {
        std::cout << "It's a tie!\n";
    }
    else if ((userchoice == 1 && computerchoice == 3) ||
             (userchoice == 2 && computerchoice == 1) ||
             (userchoice == 3 && computerchoice == 2)) {
        std::cout << "You win!\n";
    }
    else {
        std::cout << "Computer wins!\n";
    }
}

std::string choiceToString(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Unknown";
    }
}