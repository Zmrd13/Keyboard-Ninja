echo "Compiling gtests ..."
g++ -Wall -Werror -std=c++1z -I. -Lgtest/lib main.cpp -o Gtests.exe \
	LevelFileReaderTest.cpp ../lib/LevelFileReader.cpp \
	ArrProcTest.cpp \
-lgtest -pthread
