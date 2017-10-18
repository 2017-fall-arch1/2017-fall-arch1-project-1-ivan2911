all: main

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

main: func.o main.o
	cc -o $@ $^ -lm

func.o: functions.c func.h
	cc -c $(CFLAGS) func.c

main.o: main.c func.h
	cc -c $(CFLAGS) main.c



clean:
	rm -f *.o main

demo: main
	./main

