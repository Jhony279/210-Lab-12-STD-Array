// COMSC-210 | Lab 12 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <array>
using namespace std;

void populateArray(string);
void sortArray();

const int SIZE = 10;

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    array<string, SIZE> textArray;
    return 0;
}

void populateArray(string fileLoaction, array<string, SIZE>& textArray){
    ifstream inputFile;
    string text;
    // array<string, SIZE> textArray;
    inputFile.open(fileLoaction);
    if (!inputFile.good()){
        cout << "File was not found!\n";
        return;
    }
    int i = 0;
    while (getline(inputFile, text) && i < SIZE){
        textArray[i] = text;
        // cout << "inserting"<< text << endl;
        i++;
    }
}