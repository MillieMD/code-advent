//
// Created by Milli on 02/12/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>

int getCalibrationData(const std::string& line){

    int x = 0;
    char last;

    for(char c: line){

        if(isdigit(c)){

            if(x == 0){
                x += int(c - '0'); // Subtract value of ASCII '0' to get to the actual integer value of the digit
            }else{
                last = c;
            }
        }

    }

    if(last == 0){
        x = x*10 + x;
    }else{
        x = (x*10) + (last - '0');
    }

    return x;
}

int main(int argc, char* argv[]){

    if(argc < 2){

        std::cerr << "Usage: " << argv[0] << " FILE PATH" << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    std::string line;

    if(input.is_open()){

        int sum = 0;
        std::cout << "Calibrating..." << "\n";

        while(std::getline(input,line)){
            int c = getCalibrationData(line);

            sum += c;
            std::cout << c << "\n";
        }

        std::cout << "Sum of calibration data: " << sum << std::endl;
        input.close();

    }else{

        std::cerr << "Could not open file at directory: " << argv[1] << std::endl;
        return 1;
    }

    return 0;
}