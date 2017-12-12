/**
 * File: driver.cpp
 * Developer: Ruth Tonning
 * Email: tonningr@student.vvc.edu
 * Description: This program:
                1. Opens a text file
                2. Removes all punctuation
                3. Forces all letters to lowercase
                4. Extracts the words
                5. Stores the number of occurences of each word as well as the line
                   numbers on which the word occurs
                6. Sorts the words alphabetically
                7. Prints the words in this fashion:
                   word : occurence : #, #, etc. (where # is the line number)
 * Date: 12/11/17
**/
#include "libraries.h" // Holds all the necessary header files, constants, and the C++ libraries

int main()
{
  std::string text_file = "alice.txt"; // The text file that is sorted in the course of the program.
  Concord concordance(text_file);
  concordance.print();
  return 0;
}
