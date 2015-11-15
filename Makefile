project: main.o list.o
	cc main.o list.o -o project
main.o: list.h main.c
	cc -Wall -c main.c
list.o: list.c list.h
	cc -Wall -c list.c
	
