#include <iostream>
#include <fstream>
#include <set>
#include <string>

int main() {
    std::set<std::string> uniqueWords;
    std::string word;
    std::ofstream inputfile ("../data.txt");
    if (inputfile.is_open()) {
        std::cerr << "Error opening the file.\n";
        return 1;
    }

    while (inputfile.is_open()) {
        // Convert the word to lowercase to consider case-insensitive uniqueness
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Check if the word is unique and add it to the set
        if (uniqueWords.find(word) == uniqueWords.end()) {
            uniqueWords.insert(word);
        }
    }

    inputfile.close();

    // Display unique words in ascending order
    std::cout << "Unique words in ascending order:\n";
    std::cout << "../data.txt\n";
    return 0;
}
