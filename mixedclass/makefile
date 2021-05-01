mix: main.o mixed.o
	g++ -o mix main.o mixed.o

main.o: main.cpp mixed.h
	g++ -c main.cpp

mixed.o: mixed.cpp mixed.h
	g++ -c mixed.cpp

clean:
	rm *.o mix
