echo "Compiling gtests ..."
g++ -Wall -Werror -I. -Lgtest/lib main.cpp -o Gtests.exe \
	LevelFileReaderTest.cpp ../lib/LevelFileReader.cpp \
	ArrProcTest.cpp \
-lgtest -pthread
