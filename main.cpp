// COMSC-210 | Lab 12 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
using namespace std;

void populateArray(string);
void sortArray();

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    return 0;
}

void populateArray(string fileLoaction){
    ifstream inputFile;
    inputFile.open(fileLoaction);
    if (!inputFile.good()){
        return;
    }
}