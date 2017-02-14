#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "src/calc.h"

int main(int argc, char **argv)
{
  const std::vector<std::string> arguments(&argv[0], argv + argc);

  int ii = 0;
  for ( const auto &a : arguments )
    {
      std::cout << ii++ << " -> "<< a << std::endl;
    }

  std::ifstream input_file ("./in.csv");
  std::string s;
  if (input_file.is_open())
    {
      getline(input_file, s);
      std::cout << s << std::endl;
    }
  return 0;
}
