#ifndef WORD_H
#define WORD_H
#include "libraries.h"

class Word
{
public:
  Word(int line_num, std::string name); // 1. Assigns 'name' to 'm_name'
                                        // 2. Adds 'line_num' to 'm_w_on_line'
                                        // 3. Sets 'm_occur' to 1

  inline int get_occur() {return m_occur;}; // Returns the number of times a word occurs in a file
  inline void set_occur(int line_num) {m_w_on_line.push_back(line_num); m_occur++;};
  inline std::string get_word() {return m_name;};
  const void print(); // Prints out the string held by 'm_name', the number of times the word occurs
                      // (held by 'm_occur'), followed by a comma delimited list of the line numbers on which the word occurs
private:
  int m_occur;
  std::string m_name;
  std::vector<int> m_w_on_line; // Listing the line numbers on which the word occurs
};
#endif
