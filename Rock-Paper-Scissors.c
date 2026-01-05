#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int getComputer_Choice();
int getUser_Choice();
void CheckWinner(int userchoice, int computerchoice);
int main(){
    srand(time(NULL)); // Seed for random number generation
    printf("***Welcome to Rock-Paper-Scissors Game***\n");
    int userchoice = getUser_Choice();
    int computerchoice = getComputer_Choice();
    printf("Computer chose: %d\n", computerchoice);
    CheckWinner(userchoice, computerchoice);
    return 0;
}

int getComputer_Choice(){
    srand(time(NULL)); // Seed for random number generation
    int min = 1;
    int max = 3;
    int computerchoice = (rand() % (max - min + 1)) + min; // Random number between 1 and 3
    return computerchoice;
}
int getUser_Choice(){
    int userchoice;
    printf("Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ");
    scanf("%d", &userchoice);
    return userchoice;
}
void CheckWinner(int userchoice, int computerchoice){
    if(userchoice == computerchoice){
        printf("It's a tie!\n");
    }
    else if((userchoice == 1 && computerchoice == 3) || 
            (userchoice == 2 && computerchoice == 1) || 
            (userchoice == 3 && computerchoice == 2)){
        printf("You win!\n");
    }
    else{
        printf("Computer wins!\n");
    }
}