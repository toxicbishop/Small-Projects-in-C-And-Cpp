#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <windows.h> // For Sleep

// Simple Quiz Game in C++

struct Question {
    std::string questionText;
    std::vector<std::string> options;
    char correctOption; // 'A', 'B', 'C', 'D'
    std::string explanation;
};

int main (){
    // Initialize Questions
    std::vector<Question> quiz = {
        {"What is the capital of France?", {"A. Berlin", "B. Madrid", "C. Paris", "D. Rome"}, 'C', "Paris is the capital of France."},
        {"What is 2 + 2?", {"A. 3", "B. 4", "C. 5", "D. 6"}, 'B', "2 + 2 equals 4."},
        {"What is the largest planet in our solar system?", {"A. Earth", "B. Jupiter", "C. Mars", "D. Saturn"}, 'B', "Jupiter is the largest planet in the solar system."},
        {"What is the capital of Italy?", {"A. Venice", "B. Milan", "C. Naples", "D. Rome"}, 'D', "Rome is the capital of Italy."},
        {"What is the chemical symbol for water?", {"A. CO2", "B. H2O", "C. O2", "D. NaCl"}, 'B', "H2O is the chemical formula for water."},
        {"Who wrote 'Romeo and Juliet'?", {"A. Charles Dickens", "B. William Shakespeare", "C. Mark Twain", "D. Jane Austen"}, 'B', "William Shakespeare wrote 'Romeo and Juliet'."},
        {"What is the smallest prime number?", {"A. 0", "B. 1", "C. 2", "D. 3"}, 'C', "2 is the smallest prime number."},
        {"What planet is known as the Red Planet?", {"A. Venus", "B. Mars", "C. Jupiter", "D. Saturn"}, 'B', "Mars is known as the Red Planet because of iron oxide on its surface."},
        {"What is the hardest natural substance on Earth?", {"A. Gold", "B. Iron", "C. Diamond", "D. Silver"}, 'C', "Diamond is the hardest natural substance."},
        {"Who painted the Mona Lisa?", {"A. Vincent van Gogh", "B. Pablo Picasso", "C. Leonardo da Vinci", "D. Claude Monet"}, 'C', "Leonardo da Vinci painted the Mona Lisa."},
        {"What is the speed of light in vacuum?", {"A. 300,000 km/s", "B. 150,000 km/s", "C. 450,000 km/s", "D. 600,000 km/s"}, 'A', "The speed of light in vacuum is approximately 300,000 km/s."},
        {"Which continent is the Sahara Desert located in?", {"A. Africa", "B. Asia", "C. Europe", "D. Australia"}, 'A', "The Sahara Desert is located in Africa."},
        {"Who is known as the father of computers?", {"A. Charles Babbage", "B. Alan Turing", "C. Bill Gates", "D. Steve Jobs"}, 'A', "Charles Babbage is considered the father of computers."},
        {"What is the largest mammal?", {"A. Elephant", "B. Blue Whale", "C. Giraffe", "D. Hippopotamus"}, 'B', "The blue whale is the largest mammal."},
        {"Which country is known as the Land of the Rising Sun?", {"A. China", "B. Japan", "C. Korea", "D. Thailand"}, 'B', "Japan is called the Land of the Rising Sun."},
        {"What is the boiling point of water?", {"A. 90°C", "B. 100°C", "C. 80°C", "D. 120°C"}, 'B', "Water boils at 100°C at standard atmospheric pressure."},
        {"Who discovered penicillin?", {"A. Alexander Fleming", "B. Marie Curie", "C. Louis Pasteur", "D. Isaac Newton"}, 'A', "Alexander Fleming discovered penicillin."},
        {"What is the main language spoken in Brazil?", {"A. Spanish", "B. Portuguese", "C. French", "D. English"}, 'B', "Portuguese is the main language spoken in Brazil."},
        {"Which ocean is the largest?", {"A. Atlantic", "B. Indian", "C. Pacific", "D. Arctic"}, 'C', "The Pacific is the largest ocean."},
        {"What is the currency of Japan?", {"A. Yen", "B. Dollar", "C. Euro", "D. Peso"}, 'A', "The Yen is the currency of Japan."},
        {"Who invented the telephone?", {"A. Alexander Graham Bell", "B. Thomas Edison", "C. Nikola Tesla", "D. Albert Einstein"}, 'A', "Alexander Graham Bell is credited with inventing the telephone."},
        {"What is the tallest mountain in the world?", {"A. K2", "B. Everest", "C. Kilimanjaro", "D. Elbrus"}, 'B', "Mount Everest is the tallest mountain above sea level."},
        {"Which planet is closest to the sun?", {"A. Mercury", "B. Venus", "C. Earth", "D. Mars"}, 'A', "Mercury is the planet closest to the Sun."},
        {"What is the largest organ in the human body?", {"A. Heart", "B. Skin", "C. Liver", "D. Brain"}, 'B', "Skin is the largest organ of the human body."},
        {"Who is the author of 'Harry Potter'?", {"A. J.K. Rowling", "B. Enid Blyton", "C. Roald Dahl", "D. Suzanne Collins"}, 'A', "J.K. Rowling is the author of the Harry Potter series."},
        {"What is the national sport of Canada?", {"A. Ice Hockey", "B. Soccer", "C. Baseball", "D. Basketball"}, 'A', "Ice hockey is widely considered Canada's national sport."},
        {"Which element has the chemical symbol 'O'?", {"A. Oxygen", "B. Hydrogen", "C. Nitrogen", "D. Helium"}, 'A', "O is the chemical symbol for oxygen."},
        {"What is the capital of Australia?", {"A. Sydney", "B. Melbourne", "C. Canberra", "D. Brisbane"}, 'C', "Canberra is the capital of Australia."},
        {"Who painted the ceiling of the Sistine Chapel?", {"A. Michelangelo", "B. Raphael", "C. Donatello", "D. Leonardo"}, 'A', "Michelangelo painted the ceiling of the Sistine Chapel."},
        {"What is the smallest country in the world?", {"A. Monaco", "B. Vatican City", "C. San Marino", "D. Liechtenstein"}, 'B', "Vatican City is the smallest independent country in the world."},
        {"What is the longest river in the world?", {"A. Nile", "B. Amazon", "C. Yangtze", "D. Mississippi"}, 'A', "The Nile is commonly cited as the longest river in the world."},
        {"Who was the first man on the moon?", {"A. Yuri Gagarin", "B. Neil Armstrong", "C. Buzz Aldrin", "D. John Glenn"}, 'B', "Neil Armstrong was the first man to walk on the Moon."},
        {"What is the largest continent?", {"A. Africa", "B. Asia", "C. Europe", "D. Australia"}, 'B', "Asia is the largest continent by area and population."},
        {"What is the main ingredient in guacamole?", {"A. Tomato", "B. Avocado", "C. Onion", "D. Pepper"}, 'B', "Avocado is the main ingredient in guacamole."},
        {"Which country gifted the Statue of Liberty to the USA?", {"A. France", "B. Germany", "C. Italy", "D. Spain"}, 'A', "France gifted the Statue of Liberty to the United States."},
        {"What is the chemical symbol for gold?", {"A. Au", "B. Ag", "C. Fe", "D. Cu"}, 'A', "Au is the chemical symbol for gold."},
        {"Who is known as the Iron Lady?", {"A. Margaret Thatcher", "B. Angela Merkel", "C. Indira Gandhi", "D. Golda Meir"}, 'A', "Margaret Thatcher was known as the Iron Lady."},
        {"What is the capital of Egypt?", {"A. Cairo", "B. Alexandria", "C. Giza", "D. Luxor"}, 'A', "Cairo is the capital of Egypt."},
        {"Which animal is known as the King of the Jungle?", {"A. Lion", "B. Tiger", "C. Elephant", "D. Bear"}, 'A', "The lion is often referred to as the King of the Jungle."},
        {"What is the largest ocean on Earth?", {"A. Atlantic", "B. Indian", "C. Pacific", "D. Arctic"}, 'C', "The Pacific Ocean is the largest ocean on Earth."},
        {"Who wrote 'Pride and Prejudice'?", {"A. Jane Austen", "B. Emily Bronte", "C. Charlotte Bronte", "D. Louisa May Alcott"}, 'A', "Jane Austen wrote 'Pride and Prejudice'."},
        {"What is the square root of 64?", {"A. 6", "B. 7", "C. 8", "D. 9"}, 'C', "The square root of 64 is 8."},
        {"Which gas do plants absorb from the atmosphere?", {"A. Oxygen", "B. Carbon Dioxide", "C. Nitrogen", "D. Hydrogen"}, 'B', "Plants absorb carbon dioxide (CO2) for photosynthesis."},
        {"What is the capital of Spain?", {"A. Madrid", "B. Barcelona", "C. Seville", "D. Valencia"}, 'A', "Madrid is the capital of Spain."},
        {"Who is the Greek god of the sea?", {"A. Zeus", "B. Hades", "C. Poseidon", "D. Apollo"}, 'C', "Poseidon is the Greek god of the sea."},
        {"What is the largest island in the world?", {"A. Greenland", "B. Australia", "C. Borneo", "D. Madagascar"}, 'A', "Greenland is the largest island in the world."},
        {"What is the main ingredient in sushi?", {"A. Rice", "B. Fish", "C. Seaweed", "D. Soy Sauce"}, 'A', "Rice is a fundamental ingredient in sushi (vinegared rice)."},
        {"Who invented the light bulb?", {"A. Thomas Edison", "B. Nikola Tesla", "C. Alexander Graham Bell", "D. Albert Einstein"}, 'A', "Thomas Edison is credited with inventing the practical light bulb."},
        {"What is the capital of Germany?", {"A. Munich", "B. Berlin", "C. Hamburg", "D. Frankfurt"}, 'B', "Berlin is the capital of Germany."},
        {"Which country is famous for tulips?", {"A. Netherlands", "B. Belgium", "C. France", "D. Denmark"}, 'A', "The Netherlands is famous for its tulips."},
        {"What is the chemical symbol for sodium?", {"A. Na", "B. K", "C. Ca", "D. Mg"}, 'A', "Na is the chemical symbol for sodium."}
    };

    // Need to verify standardizing the options. The original code had specific indices.
    // I entered options manually above.

    int score = 0;
    int totalQuestions = quiz.size();

    std::cout << "(Using " << totalQuestions << " questions)\n";

    // Show existing high score
    std::string hsfile = "highscore.txt";
    int bestScore = -1;
    std::string bestName = "";
    
    std::ifstream hf(hsfile);
    if(hf.is_open()){
        hf >> bestScore;
        hf.ignore(); // skip newline
        std::getline(hf, bestName);
        hf.close();
    }
    
    if(bestScore >= 0) {
        std::cout << "High score: " << bestScore << " by " << bestName << "\n";
    }

    // Shuffle questions logic
    std::cout << "Shuffle questions? (y/N): ";
    std::string line;
    bool doShuffle = false;
    if (std::getline(std::cin, line)) {
        if (!line.empty() && (line[0] == 'y' || line[0] == 'Y')) {
            doShuffle = true;
        }
    }

    // Create an index vector to shuffle
    std::vector<int> order(totalQuestions);
    for(int i=0; i<totalQuestions; ++i) order[i] = i;

    if(doShuffle){
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        // Custom shuffle implementation to match original 'rand' based shuffle or use std::shuffle
        // original was a reverse loop swap
        for(int i=totalQuestions-1;i>0;i--){
            int r = std::rand() % (i+1);
            std::swap(order[i], order[r]);
        }
    }

    std::cout << "Welcome to the Quiz Game!\n";

    for(int qIdx=0; qIdx<totalQuestions; ++qIdx){
        int i = order[qIdx];
        const auto& q = quiz[i];
        
        std::cout << "\nQ" << (qIdx+1) << ". " << q.questionText << "\n";
        for(const auto& opt : q.options) {
            std::cout << opt << "\n";
        }

        char answerChar = '\0';
        while(true){
            std::cout << "Enter your answer (A-D): ";
            std::string input;
            if(!std::getline(std::cin, input)) { answerChar='\0'; break; }
            
            // Trim whitespace
            size_t first = input.find_first_not_of(" \t\r\n");
            if (first == std::string::npos) continue;
            
            answerChar = input[first];
            answerChar = std::toupper(answerChar);

            if(answerChar >= 'A' && answerChar <= 'D') break;
            std::cout << "Invalid option. Please enter A, B, C, or D.\n";
        }

        if(answerChar == q.correctOption){
            std::cout << "Correct!\n";
            score++;
        } else {
            int userIdx = answerChar - 'A';
            if (userIdx >= 0 && userIdx < 4) {
                 std::cout << "Wrong! You chose option " << answerChar << ": " << q.options[userIdx] << "\n";
            } else {
                 std::cout << "Wrong! You entered an invalid option: " << answerChar << "\n";
            }
            
            // Find correct option index
            // Assuming options are always A, B, C, D in order as originally implemented
            int correctIdx = q.correctOption - 'A';
            if (correctIdx >= 0 && correctIdx < 4) {
                 // Clean up the option string to display (remove "A. " etc if desired, but original kept it)
                 std::cout << "Correct answer: option " << q.correctOption << ": " << q.options[correctIdx] << "\n";
            }
            std::cout << "Reason: " << q.explanation << "\n";
        }
    }

    std::cout << "\nQuiz Over! Your total score is " << score << " out of " << totalQuestions << ".\n";

    // Result Classification
    std::cout << "\n---------------------------------------------\n";
    std::cout << "|   Score Range   |     Classification      |\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "|   48 - 50      |     Distinction         |\n";
    std::cout << "|   40 - 47      |     First Class         |\n";
    std::cout << "|   35 - 39      |     Second Class        |\n";
    std::cout << "|   19 - 34      |     Pass                |\n";
    std::cout << "|   0  - 18      |     Fail                |\n";
    std::cout << "---------------------------------------------\n";

    if(score < 19) {
        std::cout << "\nYour Result: Fail\n";
    } else if(score >= 48) {
        std::cout << "\nYour Result: Distinction\n";
    } else if(score >= 40) {
        std::cout << "\nYour Result: First Class\n";
    } else if(score >= 35) {
        std::cout << "\nYour Result: Second Class\n";
    } else {
        std::cout << "\nYour Result: Pass\n";
    }

    if(score > bestScore){
        std::cout << "\nNew high score! Enter your name: ";
        if(std::getline(std::cin, bestName)){
            // trim
            bestName.erase(bestName.find_last_not_of(" \n\r\t")+1);

            std::ofstream wf(hsfile);
            if(wf.is_open()){
                wf << score << "\n" << bestName << "\n";
                wf.close();
                std::cout << "High score saved.\n";
            } else {
                std::cout << "Failed to save high score.\n";
            }
        }
    }

    return 0;
}