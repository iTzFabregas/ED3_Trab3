all:
	gcc -Wall -g -o trab2 *.c

run:
	./trab2

clean:
	rm trab2 *.o *.zip *.bin

copy:
	cp ../antes/* ./

zip:
	zip trab2.zip Makefile *.c *.o *.h