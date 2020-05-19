echo "Compiling gtests ..."
g++ -Wall -Werror -I. -std=c11 -Lgtest/lib main.cpp -o Gtests.exe \
	LevelFileReaderTest.cpp ../lib/LevelFileReader.cpp \
	ArrProcTest.cpp \
-lgtest -pthread
