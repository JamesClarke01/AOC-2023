#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>

/*
each line contains calibration value
one each line:
    combine first and last digit


*/



int main(void) {

    std::ifstream puzzleFile("1.txt");
    std::string line;

    std::map<std::string, char> digMap = {
                                            {"one", '1'},
                                            {"two", '2'},
                                            {"three", '3'},
                                            {"four", '4'},
                                            {"five", '5'},
                                            {"six", '6'},
                                            {"seven", '7'},
                                            {"eight", '8'},
                                            {"nine", '9'}
                                        };
    
    int valSum = 0;


    while (getline(puzzleFile, line)) {
        std::string numString;
        std::string currentWord = "";
       
        char firstDig = -1, lastDig = -1;
        
    
        for(char letter : line) {




            if (digMap.find(currentWord) != digMap.end()) {
                if (firstDig == -1) {
                    firstDig = digMap[currentWord];
                }
                lastDig = digMap[currentWord];  
                currentWord = "";
            }

            if (isdigit(letter)) {                                
                if (firstDig == -1) {
                    firstDig = letter;
                }
                lastDig = letter;
                currentWord = "";                
            } else {
                currentWord += letter;
            }
            

        }

        if (digMap.find(currentWord) != digMap.end()) {
                if (firstDig == -1) {
                    firstDig = digMap[currentWord];
                }
                lastDig = digMap[currentWord];  
                currentWord = "";
            }


        numString = {firstDig, lastDig};
      
        valSum += std::stoi(numString);  

    }

    std::cout << valSum;

    puzzleFile.close();
}