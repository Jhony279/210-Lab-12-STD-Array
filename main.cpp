// COMSC-210 | Lab 12 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <array>
using namespace std;

const int SIZE = 10;
const string FILE_LOCATION = "C:\\Users\\lordj\\Downloads\\text.txt";

void populateArray(string, array<string, SIZE>&);
void sortArray();

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    array<string, SIZE> textArray;
    populateArray(FILE_LOCATION, textArray);
    cout << "Unsorted array (Raw Data)\n";
    for (string text : textArray) cout << text << endl;

    return 0;
}

void populateArray(string fileLoaction, array<string, SIZE>& textArray){
    ifstream inputFile;
    string text;
    // array<string, SIZE> textArray;
    inputFile.open(fileLoaction);
    if (inputFile.good()){
        int i = 0;
        while (getline(inputFile, text) && i < SIZE){
            textArray[i] = text;
            // cout << "inserting"<< text << endl;
            i++;
        }
    } else{
        cout << "File was not found!\n";
        return;
    }
}