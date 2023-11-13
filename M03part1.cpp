// File-Name: M03Part1.cpp
// Author: Ilyas Khamliche
// Date: 11/7/2023
// Purpose: create a program that analyzes student scores.
#include <iostream>
// get quiz scores for the first 16 weeks 
void getData (int scores[], int size) {
    for ( int i = 0; i < size; i++) {
        std:: cout << "Enter the score for the module " << i + 1 << ": " ;
        std:: cin >> scores[i];
    }
}
// finding the module with the highest score
int highScore(const int scores[], int size) {
    int maxScore = scores[0];
    int moduleNumber = 1;

    for (int i = 1; i < size; i++)
    {
        if (scores[i]> maxScore) {
            maxScore = scores[i];
            moduleNumber = i + 1;
        }
    }
    return moduleNumber;
}
// finding the module with the lowest score
int lowScore(const int scores[], int size) {
    int minScore = scores[0];
    int moduleNumber = 1;

    for (int i = 1; i < size; i++) {
        if (scores[i] < minScore) {
            minScore = scores[i];
            moduleNumber = i + 1;
        }
    }

    return moduleNumber;
}

int main() {
    const int size = 16;
    int quizScores[size];
// get scores from the user
    getData(quizScores, size);

// finding the highest and lowerst scores
int highestModule = highScore(quizScores, size);
int lowestModule = lowScore( quizScores, size);

// calculating the average grade

int sum = 0;
for (int i = 0; i < size; i++)
{
    sum += quizScores[i];
}
double average = static_cast<double>(sum) / size;

// print quiz scores

std:: cout << "Fall 2019 Quiz Grades: \n\n";
for (int i = 0; i < size; i++)
{
    std:: cout << "Module " << i + 1 << ": " << quizScores[i];
}
std:: cout << "\nAverage Grade: " << average << "\n\n";
std:: cout << "the lowest score was in module " << lowestModule << " with " << quizScores[lowestModule - 1] << ".\n";
std:: cout << "the highest score was in module " << highestModule << " with " << quizScores[highestModule - 1] << ".\n";

return 0;
}
