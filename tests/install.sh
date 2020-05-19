echo "Compiling gtests ..."
g++ -Wall -Werror -std=c++11 -I.  -Lgtest/lib main.cpp -o Gtests.exe \
	LevelFileReaderTest.cpp ../lib/LevelFileReader.cpp \
	ArrProcTest.cpp \
-lgtest -pthread
