#include "gtest/gtest.h"
#include "../lib/LevelFileReader.h"

#include <fstream>
#include <string>
#include <vector>

class LevelFileReaderTest: public ::testing::Test
{
protected:

  LevelFileReaderTest()
  {
    // ..
  }

  void SetUp()
  {
    this->fileStream.open(filePathPrefix + fileName);
    std::string word = "";

    while (std::getline(this->fileStream, word, '\n'))
      this->words.push_back(word);

    this->fileStream.close();
  }

  void TearDown()
  {
    // ..
  }

  ~LevelFileReaderTest()
  {
    // ..
  }

  std::ifstream fileStream;
  std::vector<std::string> words;

  const std::string filePathPrefix = "data/";
  const std::string fileName = "FileWithWords";
};


TEST_F(LevelFileReaderTest, ReadWord)
{
  this->fileStream.open(filePathPrefix + fileName);
  LevelFileReader fileReader(fileStream);

  long unsigned int i = 0;

  for (i = 0; true; i++)
  {
    std::string word = fileReader.GetWord();
    if (word == "") break;
    ASSERT_TRUE(word == words.at(i));
    ASSERT_FALSE(i >= words.size());
  }

  ASSERT_TRUE(i == words.size());
  fileStream.close();
}


TEST_F(LevelFileReaderTest, ReadAllWords)
{
  fileStream.open(filePathPrefix + fileName);
  LevelFileReader fileReader(fileStream);

  std::vector<std::string> fileReaderWords = fileReader.GetAllWords();
  ASSERT_EQ(fileReaderWords.size(), words.size());

  for (long unsigned i = 0; i < words.size(); i++)
    { ASSERT_TRUE(fileReaderWords.at(i) == words.at(i)); }
}
