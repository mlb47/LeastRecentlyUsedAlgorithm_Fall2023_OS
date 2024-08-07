run: main
	./main

main: main.o lru.o
	g++ main.o lru.o -o main

main.o: main.cpp
	g++ -c main.cpp

lru.o: lru.cpp lru.hpp
	g++ -c lru.cpp

clean:
	rm *.o main