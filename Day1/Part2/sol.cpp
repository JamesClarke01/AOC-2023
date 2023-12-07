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

    std::ifstream puzzleFile("input.txt");
    std::string line;

    int valSum = 0;

    std::map<std::string, char> digText = {
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

    std::map<int, char> digPositions;  //position, dig character
    int linecount = 0;
    while (getline(puzzleFile, line)) {        
        
        linecount++;
        digPositions.clear();
        std::string numString;
        char firstDig, lastDig;

        //add all numbers to position map
        for(int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                digPositions[i] = line[i];
            }
        }

        int pos = 0;
        int found;
        int earliestPos;
        std::string earliestStr;
        while(pos < line.length()) {
            earliestPos = line.length();
            
            for(auto pair = digText.begin(); pair != digText.end(); pair++) { //loop though all possible words
                found = line.find(pair->first, pos);  //look for substring
                if (found != -1) {   //if substring foudn
                    if(found < earliestPos) {
                        earliestPos = found;  //finding the earliest word in the string
                        earliestStr = pair->first;
                    }
                }
            }

            if(earliestPos != line.length()) {// if a word was found
                digPositions[earliestPos] = digText[earliestStr]; //add it to the mapping
                pos += (earliestPos + earliestStr.length()); //increase pos
            } else {
                break;
            }
        }

        auto firstPair = digPositions.begin();
        auto lastPair = digPositions.end();
        lastPair--;

        numString = {firstPair->second, lastPair->second};        
      
        valSum += std::stoi(numString);  
        
        /*
        std::cout << linecount;
        std::cout << ":";
        std::cout << valSum;
        std::cout << '\n';
        */

    }

    std::cout << linecount;
    
    puzzleFile.close();
}