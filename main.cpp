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
    array<double, SIZE> doubleArray;

    populateArray(FILE_LOCATION, doubleArray);
    displayArrayInfo(doubleArray);

    return 0;
}

void populateArray(string fileLoaction, array<double, SIZE>& doubleArray){
    ifstream inputFile;
    string text;
    
    inputFile.open(fileLoaction);
    if (inputFile.good()){
        int i = 0;
        double nText = 0;
        while (getline(inputFile, text) && i < doubleArray.size()){
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
            doubleArray.at(i) = nText;
            // cout << i;
            i++;
        }
    } else{
        cout << "File was not found!"<< endl << endl;
        return;
    }
}

void displayArrayInfo(array<double, SIZE>& doubleArray){
    cout << "Unsorted array (Raw Data)\n";
    for (double value : doubleArray) cout << value << endl;
}