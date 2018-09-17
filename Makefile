FileFind.out : main.o directory.o
	g++ -Wall -g -ansi -o FileFind.out main.o directory.o

main.o : main.cpp directory.h list.cpp list.h
	g++ -Wall -g -ansi -c main.cpp

directory.o : directory.cpp directory.h list.h
	g++ -Wall -g -ansi -c directory.cpp

clean :
	rm -f FileFind.out main.o directory.o
