#include "gtest/gtest.h"
#include "../lib/ArrProc.h"

#include <fstream>
#include <string>
#include <vector>

/*
 * Oops, a global variable
 * declared as an extern one (in ArrProc.h),
 * and so needs its implementation
 */
#define CURRENT_ARRAY_SIZE 100
std::string currentArray[CURRENT_ARRAY_SIZE] = {""};

class ArrProcTest: public ::testing::Test
{
protected:

  ArrProcTest()
  {
    // ..
  }

  void SetUp()
  {
    this->fileStream.open(filePathPrefix + fileName);
    std::string word = "";

    for (short i = 0; std::getline(this->fileStream, word, '\n'); i++)
    {
      ASSERT_TRUE(i < WORDS_COUNT);
      (*this).words[i] = word;
    }

    this->fileStream.close();
  }

  void TearDown()
  {
    // ..
  }

  ~ArrProcTest()
  {
    // ..
  }

  std::ifstream fileStream;

  static const short WORDS_COUNT = 100;
  std::string words[WORDS_COUNT];

  const std::string filePathPrefix = "data/";
  const std::string fileName = "FileWithWords";
};


TEST_F(ArrProcTest, ReadLevelFile)
{
  const string path = filePathPrefix + fileName;
  string testWords[WORDS_COUNT];
  ReadLevelFile(path, testWords);

  for (int i = 0; i < WORDS_COUNT; i++)
  {
    ASSERT_TRUE(words[i] == testWords[i]);
  }
}

TEST_F(ArrProcTest, ArrayWrite)
{
  std::string testCurrentArray[CURRENT_ARRAY_SIZE];

  for (int i = 0; i < CURRENT_ARRAY_SIZE; i++)
    testCurrentArray[i] = i;

  ArrayWrite(testCurrentArray);

  for (int i = 0; i < CURRENT_ARRAY_SIZE; i++)
    ASSERT_TRUE(testCurrentArray[i] == currentArray[i]);
}
