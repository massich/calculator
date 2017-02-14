#include "calc.h"

float calc::number(std::sregex_token_iterator &it)
{
  float rtn = (std::stof(it++->str()));
  return rtn;
}

float calc::operation(std::sregex_token_iterator &it)
{
  const std::sregex_token_iterator end_it;
  while ( it != end_it)
    {
      std::cout << it++->str() << std::endl;
    }
  return 4.0;
  // float rtn = calc::operation(it); it++;
  // const std::sregex_token_iterator end_it;
  // if ( it != end_it )
  // {
  //   std::cout << "multiply   " << it++->str()[0] << std::endl;
  //   return rtn*calc::number(it); it++;
  // }
  // return rtn;
}

std::string show_rest(std::sregex_token_iterator _it)
{
  std::string out;
  const std::sregex_token_iterator end_it;
  std::sregex_token_iterator it=_it;
  for (; it != end_it; ++it)
    {
      out+= it->str()+", ";
    }
  return out;
}

float calc::multiply(std::sregex_token_iterator &it)
{
  float rtn = calc::number(it);
  const std::sregex_token_iterator end_it;
  while ( it != end_it && it->str()[0] == '*' )
    {
      rtn *= calc::add(++it);
    }
  return rtn;
}


int call = 0;

float calc::add(std::sregex_token_iterator &it)
{
  int call_id = call++;
  std::cout << std::string(call_id, '\t') << "add(" << call << ")  in , rest: " << show_rest(it) <<std::endl;
  std::cout << std::string(call_id, '\t') << "add(" << call << ")  call_multiply , rest: " << show_rest(it) <<std::endl;
  float rtn = calc::multiply(it);
  std::cout << std::string(call_id, '\t') << "add(" << call << ")  L " << rtn << " rest: " << show_rest(it) <<std::endl;
  const std::sregex_token_iterator end_it;
  while ( it != end_it && (it->str()[0] == '+' || it->str()[0] == '-')  )
  {
    char op = it->str()[0];
    std::cout << std::string(call_id, '\t') << "add(" << call << ")  op " << op << ", rest: " << show_rest(it) <<std::endl;
    float rhs = calc::add(++it);
    std::cout << std::string(call_id, '\t') << "add(" << call << ")  R " << rhs << ", rest: " << show_rest(it) <<std::endl;
    switch (op){

      case '+': rtn += rhs; break;
      case '-': rtn -= rhs; break;
      default: break; //do nothing
    }
  }
  std::cout << std::string(call_id, '\t') << "add(" << call << ")  return " << rtn << ", rest: " << show_rest(it) <<std::endl;
  call--;
  return rtn;
}

float calc::compute(std::string s)
{
  std::regex delimiters_reg("[\\s,]+"); // whitespace and commas
  std::sregex_token_iterator it(s.begin(), s.end(), delimiters_reg, -1);
  float result = calc::add(it);
  return result;
}
