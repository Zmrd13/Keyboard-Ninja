#include "LevelFileReader.h"

#include <string>
#include <fstream>
#include <vector>

LevelFileReader::LevelFileReader(std::ifstream& fileStream) :
  fileStream(fileStream)
{
  // ..
}

LevelFileReader::~LevelFileReader()
{
  // ..
}

std::vector<std::string> LevelFileReader::GetAllWords()
{
  std::vector<std::string> words{};

  while (true)
  {
    std::string word = GetWord();
    if (word != "") words.push_back(word);
    else break;
  }

  return words;
}

std::string LevelFileReader::GetWord()
{
  std::string word = "";
  getline(fileStream, word, '\n');
  return word;
}
