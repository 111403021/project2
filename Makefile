try: aaa.o lista.o
	cc aaa.o lista.o -o try
aaa.o: lista.h aaa.c
	cc -Wall -c aaa.c 
lista.o: lista.c lista.h
	cc -Wall -c lista.c
