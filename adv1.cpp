// reading a text file
#include <queue>
#include <numeric>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>


std::vector<int> readInputToVector(std::string fileName)
{
    std::fstream inFile;
    inFile.open(fileName); //app is append which means it will put the text at the end

    std::vector<int> inNumbers;
    if (inFile.is_open())
    {
      std::string line;
      while(std::getline(inFile, line))
      {
        if(line.length())
        {
          int inNumber = std::stoi(line);
          inNumbers.push_back(inNumber);
        }
      }
      inFile.close();
    }
    else
    {
      std::cout << "nada" << std::endl;
    }
    return inNumbers;
}

int calcFuelForMass(int mass)
{
      return (std::floor(mass/3) - 2);
}

void calcFuel(std::vector<int>& mass, std::vector<int>& fuel)
{
   std::queue<int> q;
   for (int i=0; i < mass.size(); ++i)
   {
    q.push(mass[i]);
   }
   std::cout << "im here" << std::endl;
// 142195
while (!q.empty())
  {
    int current_fuel(calcFuelForMass(q.front()));
    if ( current_fuel > 0)
    {
      fuel.push_back(current_fuel);
      q.push(current_fuel);
    }
    q.pop();
  }
}

int main () {
    std::vector<int> mass;
    std::vector<int> result;

    mass=readInputToVector("adv_input.txt");
    calcFuel(mass, result);
    int total = 0;
    for (int i=0; i < result.size(); ++i) 
    {
      total += result[i];
    }
    


    std::cout << "Das Ergebnis ist " << total << std::endl;

    return 0;
}
