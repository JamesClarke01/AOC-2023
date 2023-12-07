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

    std::ifstream puzzleFile("testcase.txt");
    std::string line;

    int valSum = 0;


    while (getline(puzzleFile, line)) {
        std::string numString;
        
       
        char firstDig = -1, lastDig = -1;
        
    
        for(char letter : line) {


            if (isdigit(letter)) {                                
                if (firstDig == -1) {
                    firstDig = letter;
                }
                lastDig = letter;              
            }
            

        }


        numString = {firstDig, lastDig};
      
        valSum += std::stoi(numString);  

    }

    std::cout << valSum;

    puzzleFile.close();
}