house: house.o main.o
	g++ house.o main.o -o house

house.o: house.cpp house.h
	g++ -c house.cpp

main.o: main.cpp house.h
	g++ -c main.cpp

clean:
	rm -f *.o house
