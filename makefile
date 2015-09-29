try: bus.o
	cc bus.o -o try
bus.o: bus.c
	cc -Wall -c bus.c
