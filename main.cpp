// COMSC-210 | Lab 12 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>  
#include <array>
using namespace std;

const int SIZE = 30;
const int INV_ARG = 100;
const string FILE_LOCATION = "C:\\Users\\lordj\\Downloads\\text.txt";

void populateArray(string, array<double, SIZE>&, array<string, SIZE>&);
void displayArrayInfo(array<double, SIZE>&);
void displayInvalidArray(array<string, SIZE>&);

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    array<double, SIZE> tempArray;
    array<string, SIZE> iArgArray;
    fill(tempArray.begin(), tempArray.end(), 0.0);
    fill(iArgArray.begin(), iArgArray.end(), "");

    populateArray(FILE_LOCATION, tempArray, iArgArray);
    displayArrayInfo(tempArray);

    return 0;
}

void populateArray(string fileLoaction, array<double, SIZE>& lArray, array<string, SIZE>& iArgArray){
    ifstream inputFile;
    string text;
    
    inputFile.open(fileLoaction);
    if (inputFile.good()){
        static int i = 0;
        static int lineCount = 1;
        static double nText = 0;
        while (getline(inputFile, text) && i < lArray.size()){
            // If Line is empty, skip to next iteration
            if (text.empty()){
                lineCount++;
                continue;
            }
            // If string cant convert to double, skip to next iteration
            try {
                nText = stod(text);
            } catch (const invalid_argument& e) {
                if (lineCount < SIZE){
                    iArgArray.at(lineCount) = text;
                }
                lineCount++;
                continue;
            }
            // If line is valid, add to array
            lArray.at(i) = nText;
            lineCount++;
            i++;
        }
    } else{
        cout << "\n!File was not found!" << endl << endl;
        return;
    }
    cout << endl;
}

void displayArrayInfo(array<double, SIZE>& lArray){
    // End function if array is empty
    if (accumulate(lArray.begin(), lArray.end(), 0.0) == 0.0){
        cout << "!Array is empty!" << endl;
        return;
    }

    cout << "--- Temperature (F°) Array Data ---\n";
    static int i = 0;
    for (double value : lArray) {
        if (i % 7 == 0) {
            cout << "Week " << i / 7 + 1 << ": ";
        }
        cout << value << ", ";
        i++;
        if (i % 7 == 0) {
            cout << "\n";
        }
    };
    cout << "  Hottest day: " 
        << *max_element(lArray.begin(), lArray.end()) << "°F" << endl;
    cout << "  Coldest day: " 
        << *min_element(lArray.begin(), lArray.end()) << "°F" << endl;
    cout << "  Average temperature in the month: " 
        << accumulate(lArray.begin(), lArray.end(), 0.0)/lArray.size() << "°F" << endl;
}

void displayInvalidArray(array<string, SIZE>& invArray){
    cout << "\n--- Invalid Data ---";
}