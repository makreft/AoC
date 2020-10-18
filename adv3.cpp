#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

typedef struct
{
  char direction; // R, L, U, D
  int nbr_of_steps; // number of steps in direction
} WireEdge;

std::vector<std::string> split ( const std::string& string, char delimiter )
{
  std::vector<std::string> splits;
  std::string split;
  std::istringstream s_stream ( string );
  while ( std::getline ( s_stream, split, delimiter ) )
  {
     splits.push_back ( split );
  }
  return splits;
}

std::vector<std::vector<std::string>> ifstreamToVector ( std::ifstream& file_stream )
{
  std::vector<std::vector<std::string>> wires;
  std::string line;
  std::vector<std::string> words;

  while( file_stream >> line )
  {
    words = split( line, ',' );
    wires.push_back( words );
  }
  return wires;
}

int main()
{
  std::ifstream file( "adv3_input.txt" );
  std::vector<std::vector<std::string>> wires( ifstreamToVector( file ) );

  for ( auto ele: wires[0] )
  {
    std::cout << ele << std::endl;
  }
}