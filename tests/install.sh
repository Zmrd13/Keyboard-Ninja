echo "Compiling gtests ..."
g++ -Wall main.cpp \
  LevelFileReaderTest.cpp ../lib/LevelFileReader.cpp \
-o Gtests.exe -lgtest
