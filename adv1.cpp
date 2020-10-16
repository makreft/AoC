// reading a text file
#include <iostream>
#include <fstream>
#include <string>

int main () {
    std::string line;
    std::ifstream myfile ("adv_input.txt");
    if (myfile.is_open())
    {
        while ( std::getline (myfile,line) )
        {
            std::cout << line << '\n';
        }
        myfile.close();
    }

    else std::cout << "Unable to open file";

    return 0;
}