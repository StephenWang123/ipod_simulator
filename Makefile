ipod.out: main.o song.o
	g++ -g main.o song.o -o ipod.out

main.o: main.cpp
	g++ -Wall -ansi -c main.cpp
	
song.o: song.cpp song.h
	g++ -Wall -ansi -c song.cpp

clean:
	rm -f main.o ipod.out
