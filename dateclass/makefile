date: date.o main.o
	g++ date.o main.o -o run

date.o: date.cpp date.h
	g++ -c date.cpp

main.o: main.cpp date.h
	g++ -c main.cpp

clean:
	rm -f *.o run
