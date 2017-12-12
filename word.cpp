#include "libraries.h"

Word::Word(int line_num, std::string name)
{
  m_occur = 1;
  m_w_on_line.push_back(line_num);
  m_name = name;
}

const void Word::print()
{
  std::cout << m_name << " : " << m_occur << " : ";
  for (int i = 0; i < m_w_on_line.size(); i++)
  {
    std::cout << m_w_on_line[i];
    if (i < (m_w_on_line.size() - 1))
      std::cout << ", ";
  }
  std::cout << std::endl;
}
