#include <string>
#include <fstream>
#include <vector>

class LevelFileReader
{
public:

  LevelFileReader(std::ifstream& fileStream);
  ~LevelFileReader();
  std::vector<std::string> GetAllWords();
  std::string GetWord();

private:

  std::ifstream& fileStream;
};
