all:
	g++ -c *.cpp
	g++ -o trab3 *.o 

clean:
	rm *.o

run:
	./trab3