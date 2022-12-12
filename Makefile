all:
	g++ -g -c *.cpp
	g++ -g -o trab3 *.o 

clean:
	rm *.o *.bin trab3 *.zip

copy:
	cp ../antes/* ./

run:
	./trab3

zip:
	zip trab3.zip Makefile *.cpp *.hpp