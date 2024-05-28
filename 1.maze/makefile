all: main.out

main.out: main.o functions.o
	g++ -o main.out main.o functions.o 

main.o: main.cpp functions.h
	g++ -c main.cpp -o main.o

functions.o: functions.cpp functions.h
	g++ -c functions.cpp -o functions.o

clean: rm *.o *.out
