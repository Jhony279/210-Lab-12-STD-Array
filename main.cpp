// COMSC-210 | Lab 12 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <algorithm>    // for sort(), find(), max_element(), min_element()
#include <numeric>  // for accumulate()
#include <array>
using namespace std;

const int SIZE = 30;
const string FILE_LOCATION = "C:\\Users\\lordj\\COMSC-210\\projects\\210-lab-12\\text.txt";

void populateArray(string, array<double, SIZE>&, array<string, SIZE>&, array<int, SIZE>&);
void displayArrayInfo(array<double, SIZE>&);
void displayInvalidArray(array<string, SIZE>&, array<int, SIZE>&);

/**
 * @brief Reads a text file filled with temperature data, populates an array with it
 *        while keeping track of invalid entries and their line, then displays the array
 *        data and invalid entries.
*/
int main() {
    // The array to hold the data
    array<double, SIZE> tempArray;
    fill(tempArray.begin(), tempArray.end(), 0.0);
    // The array to hold invalid entries
    array<string, SIZE> iArgArray;
    fill(iArgArray.begin(), iArgArray.end(), "");
    // Array to hold line numbers of invalid entries
    array<int, SIZE> lineArray;
    fill(lineArray.begin(), lineArray.end(), 0);

    // Populate array with file data, then display array info and invalid entries
    populateArray(FILE_LOCATION, tempArray, iArgArray, lineArray);
    displayArrayInfo(tempArray);
    displayInvalidArray(iArgArray, lineArray);

    return 0;
}

/**
 * @brief Reads a text file, populates an array with it while keeping track of invalid
 *        entries and their line.
 * @param fileLoaction The location of the text file to read from
 * @param tArray The array to hold the temperature data
 * @param iArgArray The array to hold the invalid entries
 * @param iArray The array to hold the line numbers of the invalid entries
*/
void populateArray(string fileLoaction, array<double, SIZE>& tArray, array<string,
                    SIZE>& iArgArray, array<int, SIZE>& iArray){
    ifstream inputFile;
    string text;
    
    inputFile.open(fileLoaction);
    if (inputFile.good()){
        static int i = 0;
        static int j = 0;
        static int lineCount = 1;
        static double nText = 0;
        while (getline(inputFile, text) && i < tArray.size()){
            // If Line is empty, skip to next line
            if (text.empty()){
                lineCount++;
                continue;
            }
            // If string cant convert to double, skip to next line
            try {
                nText = stod(text);
            } catch (const invalid_argument& e) {
                if (lineCount <= tArray.size()){
                    // Store invalid entry and line number in respective arrays
                    iArgArray.at(j) = text;
                    iArray.at(j) = lineCount;
                    j++;
                }
                lineCount++;
                // continue;
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

/**
 * @brief Displays the data in the array, as well as the hottest day, coldest day, and 
 *        average temperature.
 * @param tArray The array to hold the temperature data
*/
void displayArrayInfo(array<double, SIZE>& tArray){
    // End function if array is empty
    if (accumulate(tArray.begin(), tArray.end(), 0.0) == 0.0){
        cout << "!Array is empty!" << endl;
        return;
    }

    cout << "--- Temperature (F°) Array Data ---\n";
    static int week = 0;
    // loop through array and display data
    for (int j : tArray) {
        // Display week number at the start of each week
        if (week % 7 == 0) {
            cout << "Week " << week / 7 + 1 << ": ";
        }
        cout << j << ", ";
        week++;
        // If week is over, start new line
        if (week % 7 == 0) {
            cout << "\n";
        }
    };
    cout << "\n  Hottest day: " 
        << *max_element(tArray.begin(), tArray.end()) << "°F" << endl;
    cout << "  Coldest day: " 
        << *min_element(tArray.begin(), tArray.end()) << "°F" << endl;
    cout << "  Average temperature in the month: " 
        << accumulate(tArray.begin(), tArray.end(), 0.0)/tArray.size() << "°F" << endl;
}

/**
 * @brief Displays the invalid entries in the array, as well as their line number.
 * @param invArray The array to hold the invalid entries
 * @param iArray The array to hold the line numbers of the invalid entries
*/
void displayInvalidArray(array<string, SIZE>& invArray, array<int, SIZE>& iArray){
    cout << "\n--- Invalid Data ---" << endl;
    static int i = 0;
    // loop throguh invalid data array and display data and line number of each entry
    for (string data : invArray){
        // If data is empty skip to next entry
        if (data == ""){
            continue;
        }
        cout << "  Improper Data: " << data << " (At line " 
            << iArray.at(i) << ")"<< endl;
        i++;
    }
}