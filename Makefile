all:
	g++ -c *.cpp
	g++ -o trab3 *.o 

clean:
	rm *.o *.bin

copy:
	cp ../antes/* ./

run:
	./trab3