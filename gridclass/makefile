grid: grid.o trapped.o
	g++ grid.o trapped.o -o grid

grid.o: grid.cpp grid.h
	g++ -c grid.cpp

trapped.o: trapped.cpp grid.h
	g++ -c trapped.cpp

clean:
	rm -f *.o grid
