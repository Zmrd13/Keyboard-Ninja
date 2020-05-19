echo "Compiling gtests ..."
g++ -Wall -Werror -std=c++1z -Igoogletest/include -Igoogletest -Lgoogletest/lib googletest/src/gtest-all.cc main.cpp -o Gtests.exe \
	LevelFileReaderTest.cpp ../lib/LevelFileReader.cpp \
	ArrProcTest.cpp \
-lgtest -pthread
