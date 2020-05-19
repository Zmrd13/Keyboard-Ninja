echo "Compiling gtests ..."
g++ -Wall -Werror -std=c++17 -I. -Lgtest/lib main.cpp -o Gtests.exe \
	LevelFileReaderTest.cpp ../lib/LevelFileReader.cpp \
	ArrProcTest.cpp \
-lgtest -pthread
