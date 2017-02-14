#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <regex>
#include <iostream>

#include "calc.h"

TEST ( dummy, dummy )
{
  std::string s = "split on ,   whitespace and, commas  ";
  std::regex delimiters_reg("[\\s,]+"); // whitespace and commas
  std::sregex_token_iterator it(s.begin(), s.end(), delimiters_reg, -1);
  std::sregex_token_iterator reg_end;

  for(; it!=reg_end; it++)
    std::cout << it->str() << '\n';

  ASSERT_EQ ( true, true );
}


TEST ( dummy, single_number )
{
  float result = calc::compute("4");
  ASSERT_EQ ( 4.0, result );
}

TEST ( simple_op, add )
{
  float result = calc::compute("2,+,2");
  ASSERT_EQ ( 4.0, result );
}


TEST ( simple_op, substratcion )
{
  float result = calc::compute("6,-,2");
  ASSERT_EQ ( 4.0, result );
}

TEST ( simple_op, multiply )
{
  float result = calc::compute("2,*,2");
  ASSERT_EQ ( 4.0, result );
}

TEST ( simple_op, div )
{
  float result = calc::compute("6,/,2");
  ASSERT_EQ ( 3.0, result );
}

TEST ( multiple_op, add )
{
  float result = calc::compute("2,+,1,+,1");
  ASSERT_EQ ( 4.0, result );
}

TEST ( multiple_op, add_sub )
{
  float result = calc::compute("2,-,1,+,1");
  ASSERT_EQ ( 3.0, result );
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
