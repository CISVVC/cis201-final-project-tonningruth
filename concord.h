#ifndef CONCORD_H
#define CONCORD_H
#include "libraries.h"

class Concord
{
public:
  Concord(std::string); // 1. Opens a text file
                        // 2. Reads in lines of data from the file.
                        // 3a. Calls on the function 'remove_punc' to remove a pre-designated list of punctuation symbols
                        // 3b. Forces string to lowercase
                        // 4. Hands the string to the function 'get_words' to construct Word objects
                        // 5. Closes the file

  const void print(); // Prints the records held by the Words objects pointed to by the vector of Word pointers 'm_sorted_concord'
private:
  void remove_punc(std::string& buffer); // Uses a pre-designated array of puctuation characters 'PUNC_ARRAY'; removes said characters
  std::vector<Word> m_concord;
  std::vector<Word*> m_sorted_concord;

  void sort(); // 1. Extracts the data held by the string variables associated with the Word objects in the vector 'm_concord'
               // 2. Stores these strings in a vector and then sorts them alphabetially
               // 3. Iterates through the sorted vector of strings, making a call to the function 'search'
               // 4. Stores the addresses returned by 'search' in the vector 'm_sorted_concord'

  bool search(std::string key, Word*& target); // 1. Linear search through the vector 'm_concord'
                                               // 2. Searches for the Word object that contains the target string held by 'key'
                                               // 3. Assigns the address of the targeted Word object to the pointer 'target'

  void get_words(int line_num, std::string& buffer); // 1. Hands 'buffer' to a stringstream
                                                     // 2. Extracts words from the stringstream
                                                     // 3a. Makes a call to 'search' to check for a previous occurence of the word
                                                     // 3b. If the word is already associated with a Word object, the object's occurence counter and line number list are updated
                                                     // 3c. If the word is not associated with a previously constructed Word object, a new object is constructed and added to the vector 'm_concord'

  void lower_case(std::string& buffer); // Forces 'buffer' to lowercase
};
#endif
