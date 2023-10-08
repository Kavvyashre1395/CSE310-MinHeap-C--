EXEC = run
CC = g++
CFLAGS = -c -Wall

# $(EXEC) has the value of shell variable EXEC, which is run.
# run depends on the files main.o somefile.o
$(EXEC)	: main.o heap.o util.o
# run is created by the command g++ -o run main.o somefile.o
	$(CC) -o $(EXEC) main.o heap.o util.o

# main.o depends on the files main.h main.c
# main.o is created by the command g++ -c -Wall main.c
main.o	: main.cpp 
	$(CC) $(CFLAGS) main.cpp

heap.o	: heap.h heap.cpp
	$(CC) $(CFLAGS) heap.cpp

util.o	: util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

clean	:
	rm *.o