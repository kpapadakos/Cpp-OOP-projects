string: mystring.o main.o
	g++ mystring.o main.o -o string

mystring.o: mystring.cpp mystring.h
	g++ -c mystring.cpp

main.o: main.cpp mystring.h
	g++ -c main.cpp

clean:
	rm -f *.o string
