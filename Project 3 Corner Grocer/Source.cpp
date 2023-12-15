#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

using namespace std;

//read input file and count word frequency
void readInputFile(map<string, int>& wordFrequency) {
    ifstream inputFile("CS210_Project_Three_Input_File.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string word;
    while (inputFile >> word) {
        wordFrequency[word]++;
    }

    inputFile.close();
}

//write frequency into a new file
void writeDataFile(const map<string, int>& wordFrequency) {
    ofstream dataFile("frequency.dat");
    if (!dataFile.is_open()) {
        cout << "Error creating data file." << endl;
        return;
    }

    for (const auto& entry : wordFrequency) {
        dataFile << entry.first << " " << entry.second << endl;
    }

    dataFile.close();
}
//print func for word frequency
void printWordFrequency(const map<string, int>& wordFrequency) {
    for (const auto& entry : wordFrequency) {
        cout << entry.first << " " << entry.second << endl;
    }
}
//print histogram
void printHistogram(const map<string, int>& wordFrequency) {
    for (const auto& entry : wordFrequency) {
        cout << entry.first << " ";
        for (int i = 0; i < entry.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    //map to hold words and frequency
    map<string, int> wordFrequency;

    readInputFile(wordFrequency);

    //cout menu options
    while (true) {
        cout << "Menu:\n"
            << "1. Search for a word\n"
            << "2. Print word frequency\n"
            << "3. Print histogram\n"
            << "4. Exit\n"
            << "Choose an option: ";
        //accept user input
        int choice;
        cin >> choice;
        //switch case for input default for invalid options
        switch (choice) {
        case 1: {
            string wordToSearch;
            cout << "Enter the word to search: ";
            cin >> wordToSearch;

            cout << "Frequency of " << wordToSearch << ": " << wordFrequency[wordToSearch] << endl;
            break;
        }
        case 2:
            printWordFrequency(wordFrequency);
            writeDataFile(wordFrequency);
            break;
        case 3:
            printHistogram(wordFrequency);
            break;
        case 4:
            writeDataFile(wordFrequency);
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
