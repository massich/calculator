#pragma once
#include <regex>
#include <iostream>

namespace calc
{
  float multiply(std::sregex_token_iterator &it);
  float multiply_(std::sregex_token_iterator &it);
  float add(std::sregex_token_iterator &it);
  float operation(std::sregex_token_iterator &it);
  float number(std::sregex_token_iterator &it);
  float compute(std::string s);
}
