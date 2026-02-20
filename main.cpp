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
    return 0;
}

array<string, SIZE> populateArray(string fileLoaction){
    ifstream inputFile;
    string text;
    array<string, SIZE> textArray;
    inputFile.open(fileLoaction);
    if (!inputFile.good()){
        cout << "File was not found!\n";
        return;
    }
    while (getline(inputFile, text)){
        cout << text;
    }
    r
}