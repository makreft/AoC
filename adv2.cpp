// reading a text file
#include <queue>
#include <numeric>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

void getNumberFromString( std::string str, std::vector<int>& vect ) {
std::stringstream ss( str );
    for( int i; ss >> i; )
    {
        vect.push_back( i );
        if( ss.peek() == ',' )
            ss.ignore();
    }
}

std::vector<int> readInputToVector( std::string fileName )
{
    std::fstream inFile;
    inFile.open( fileName ); //app is append which means it will put the text at the end

    std::vector<int> inNumbers;
    if(inFile.is_open() )
    {
      std::string line;
      while(std::getline( inFile, line ) )
      {
        if(line.length())
        {
          getNumberFromString( line, inNumbers );
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

int calcFuelForMass( int mass )
{
    return( std::floor( mass / 3 ) - 2 );
}

void calcFuel( std::vector<int>& mass, std::vector<int>& fuel )
{
  std::queue<int> q;
  for( int i=0; i < mass.size(); ++i )
  {
    q.push( mass[i] );
  }
  std::cout << "im here" << std::endl;

  while( ! q.empty() )
  {
    int current_fuel( calcFuelForMass( q.front() ) );
    if( current_fuel > 0 )
    {
      fuel.push_back( current_fuel );
      q.push( current_fuel );
    }
    q.pop();
  }
}

std::vector <std::vector<int> > inputToIntcodeFormat( std::vector<int> input )
{
  std::vector <std::vector<int> > formatted;
  std::vector<int> intcode;

  int op_len=0;

  for( int i=0; i < input.size(); ++i )
  {
    if( op_len < 4 )
    {
      intcode.push_back( input[i] );
      op_len++;
    }
    else
    {
      formatted.push_back( intcode );
      op_len=0;
      intcode.clear();
    }
  }
  return formatted;
}

void add( int index, std::vector<int>& input )
{
  // intcode = [opcode, position of val1, position of val2, store result to position]
  int pos1 = input[index+1];
  int pos2 = input[index+2];
  int result = input[pos1] + input[pos2];
  input[input[index + 3]] = result;
}
void multiply( int index, std::vector<int>& input )
{
  // intcode = [opcode, position of val1, position of val2, store result to position]
  int pos1 = input[index+1];
  int pos2 = input[index+2];
  int result = input[pos1] * input[pos2];
  input[input[index + 3]] = result;
}
void calcIntcode( std::vector<int>&memory )
{
  for( int i=0; i<memory.size(); i+=4 )
  {
    int opcode = memory[i];
    if(opcode == 1)
    {
      add( i, memory );
    }
    else if( opcode == 2 )
    {
      multiply( i, memory );
    }
    else if( opcode == 99 )
    {
      break;
    }
    else
    {
      std::cout << "unexpected opcode" << std::endl;
      break;
    }
  }
}

int main () 
{
  std::string file_name( "adv2_input.txt" );
  std::vector<int> input; // input = initial memory of intcode computer

  input = readInputToVector( file_name );
  int instruction_ptr = 0;

  std::vector<int> memory( input );
  for( int noun=0; noun < 100; ++noun )
  {
    for( int verb=0; verb < 100; ++verb )
    {
      memory = input;
      memory[1] = noun;
      memory[2] = verb;
      calcIntcode( memory );
      if( memory[0] == 19690720 )
      {
        std::cout << "Noun: " << noun << " Verb: " << verb << std::endl;
        return 0;
      }
    }
  }

  std::cout << memory[0] << std::endl;
}