// COMSC-210 | Lab 12 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>  
#include <array>
using namespace std;

const int SIZE = 30;
const string FILE_LOCATION = "C:\\Users\\lordj\\Downloads\\text.xt";

void populateArray(string, array<double, SIZE>&);
void displayArrayInfo(array<double, SIZE>&);
void sortArray(array<double, SIZE>&);

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    array<double, SIZE> tempArray;
    fill(tempArray.begin(), tempArray.end(), 0.0);

    populateArray(FILE_LOCATION, tempArray);
    displayArrayInfo(tempArray);

    return 0;
}

void populateArray(string fileLoaction, array<double, SIZE>& lArray){
    ifstream inputFile;
    string text;
    
    inputFile.open(fileLoaction);
    if (inputFile.good()){
        static int i = 0;
        static double nText = 0;
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

    cout << "--- Temperature Array Data ---\n";
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
        << *max_element(lArray.begin(), lArray.end()) << endl;
    cout << "  Coldest day: " 
        << *min_element(lArray.begin(), lArray.end()) << endl;
    cout << "  Average temperature in the month: " 
        << accumulate(lArray.begin(), lArray.end(), 0.0) / lArray.size() << endl;
}