CC=gcc
NORME_FLAGS=-std=c99 
LDFLAGS= -lcmocka

all:queens test_main test_queens

queens: main.o queens.o
	$(CC) -o $@ $^

main.o:main.c queens.h rdtsc.h
	$(CC) $(NORME_FLAGS) -c -o $@ $<
 
queens.o:queens.c queens.h
	$(CC) $(NORME_FLAGS) -O3 -c -o $@ $<

test_queens:test_queens.o
	$(CC) -o $@ $^ $(LDFLAGS) 
	
test_queens.o:test_queens.c queens.c
	$(CC) $(NORME_FLAGS) -O0 -g -c -o $@ $<
	
test_main:test_main.o
	$(CC) -o $@ $^ $(LDFLAGS) 

test_main.o:test_main.c main.c
	$(CC) $(NORME_FLAGS) -O0 -g -c -o $@ $<
clean:
	rm -f *.o queens test_main test_queens

.PHONY:clean
	







