
runme: main.o NNSet.o
	g++ -o runme -Wall -ansi -pedantic -std=c++20 main.o NNSet.o

NNSet.o: NNSet.cpp NNSet.hpp
	g++ -c -Wall -ansi -pedantic -std=c++20 NNSet.cpp

main.o: main.cpp NNSet.hpp
	g++ -c -Wall -ansi -pedantic -std=c++20 main.cpp


