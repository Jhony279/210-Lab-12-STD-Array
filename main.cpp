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

void populateArray(string, array<double, SIZE>&, array<string, SIZE>&, array<int, SIZE>&);
void displayArrayInfo(array<double, SIZE>&);
void displayInvalidArray(array<string, SIZE>&);

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    array<double, SIZE> tempArray;
    fill(tempArray.begin(), tempArray.end(), 0.0);
    array<string, SIZE> iArgArray;
    fill(iArgArray.begin(), iArgArray.end(), "");
    array<int, SIZE> lineArray;
    fill(lineArray.begin(), lineArray.end(), 0);

    populateArray(FILE_LOCATION, tempArray, iArgArray, lineArray);
    displayArrayInfo(tempArray);

    return 0;
}

void populateArray(string fileLoaction, array<double, SIZE>& tArray, array<string, SIZE>& iArgArray, array<int, SIZE>& lArray){
    ifstream inputFile;
    string text;
    
    inputFile.open(fileLoaction);
    if (inputFile.good()){
        static int i = 0;
        static int j = 0;
        static int lineCount = 1;
        static double nText = 0;
        while (getline(inputFile, text) && i < tArray.size()){
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
                    iArgArray.at(j) = text;
                    j++;
                    lArray.at(j) = lineCount;
                }
                lineCount++;
                continue;
            }
            // If line is valid, add to array
            tArray.at(i) = nText;
            lineCount++;
            i++;
        }
    } else{
        cout << "\n!File was not found!" << endl << endl;
        return;
    }
    cout << endl;
}

void displayArrayInfo(array<double, SIZE>& tArray){
    // End function if array is empty
    if (accumulate(tArray.begin(), tArray.end(), 0.0) == 0.0){
        cout << "!Array is empty!" << endl;
        return;
    }

    cout << "--- Temperature (F°) Array Data ---\n";
    static int i = 0;
    for (double value : tArray) {
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
        << *max_element(tArray.begin(), tArray.end()) << "°F" << endl;
    cout << "  Coldest day: " 
        << *min_element(tArray.begin(), tArray.end()) << "°F" << endl;
    cout << "  Average temperature in the month: " 
        << accumulate(tArray.begin(), tArray.end(), 0.0)/tArray.size() << "°F" << endl;
}

void displayInvalidArray(array<string, SIZE>& invArray){
    cout << "\n--- Invalid Data ---" << endl;

}