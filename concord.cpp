#include "libraries.h"

Concord::Concord(std::string file_name)
{
  std::ifstream infile;
  infile.open(file_name.c_str());
  if (infile.fail())
  {
    std::cout << "Error opening " << file_name << std::endl;
    exit (EXIT_FAILURE);
  }
  std::string buffer;
  int line_num = 1;
  while (!infile.eof())
  {
    std::getline(infile, buffer);
    remove_punc(buffer);
    lower_case(buffer);
    get_words(line_num, buffer);
    line_num++;
  }
  sort();
  infile.close();
}

void Concord::remove_punc(std::string& buffer)
{
  for (int i = 0; i < PUNC_SIZE; i++)
  {
    buffer.erase(std::remove(buffer.begin(), buffer.end(), PUNC_ARRAY[i]), buffer.end());
  }
}

void Concord::lower_case(std::string& buffer)
{
  for (int i = 0; i < buffer.size(); i++)
  {
    buffer[i] = tolower(buffer[i]);
  }
}

void Concord::get_words(int line_num, std::string& buffer)
{
  std::stringstream line(buffer);
  std::string word;
  while (line >> word)
  {
    Word* temp;
    if (search(word, temp))
      temp->set_occur(line_num);
    else
    {
      Word word_obj(line_num, word);
      m_concord.push_back(word_obj);
    }
  }
}

bool Concord::search(std::string key, Word*& word)
{
  bool found = false;
  int i;

  for (i = 0; i < m_concord.size(); i++)
  {
    if (key == m_concord[i].get_word())
      break;
  }
  if (i < m_concord.size())
  {
    found = true;
    word = &m_concord[i];
  }
  return found;
}

void Concord::sort()
{
  std::vector<std::string> names;

  for (int i = 0; i < m_concord.size(); i++)
  {
    names.push_back(m_concord[i].get_word());
  }
  std::sort(names.begin(), names.end());
  Word* word_temp;
  for (int i = 0; i < names.size(); i++)
  {
    if (search(names[i], word_temp))
      m_sorted_concord.push_back(word_temp);
  }
}

const void Concord::print()
{
  for (int i = 0; i < m_sorted_concord.size(); i++)
  {
    m_sorted_concord[i]->print();
    std::cout << std::endl;
  }
}
