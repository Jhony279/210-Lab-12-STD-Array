// COMSC-210 | Lab 12 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <array>
using namespace std;

const int SIZE = 30;
const string FILE_LOCATION = "C:\\Users\\lordj\\Downloads\\text.txt";

void populateArray(string, array<double, SIZE>&);
void displayArrayInfo(array<double, SIZE>&);
void sortArray(array<double, SIZE>&);

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    array<double, SIZE> tempArray;

    populateArray(FILE_LOCATION, tempArray);
    displayArrayInfo(tempArray);

    return 0;
}

void populateArray(string fileLoaction, array<double, SIZE>& lArray){
    ifstream inputFile;
    string text;
    
    inputFile.open(fileLoaction);
    if (inputFile.good()){
        int i = 0;
        double nText = 0;
        while (getline(inputFile, text) && i < lArray.size()){
            // If Line is empty, skip to next iteration
            if (text.empty()){
                continue;
            }
            // If string cant convert to double, skip to next iteration
            try {
                nText = stod(text);
            } catch (const invalid_argument& e) {
                cout << "Invalid data inside file: " << fileLoaction << endl;
                cout << " Invalid Data: " << text << endl;
                continue;
            }
            // If line is valid, add to array
            lArray.at(i) = nText;
            i++;
        }
    } else{
        cout << "File was not found!";
        return;
    }
    cout << " " << endl;
}

void displayArrayInfo(array<double, SIZE>& lArray){
    cout << "--- Unsorted array (Raw Data) ---\n";
    if (lArray.empty()){
        cout << "Array is empty!" << endl;
        return;
    }
    for (double value : lArray) cout << value << endl;
}