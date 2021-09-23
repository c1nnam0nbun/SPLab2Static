CC = g++
CFLAGS = -c -Wall

all: clean lab2

lab2: main.o database.a
	$(CC) -lm -o lab2 main.o -L -l: database.a

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

employee.o: employee.cpp
	$(CC) $(CFLAGS) employee.cpp

database.o: database.cpp
	$(CC) $(CFLAGS) database.cpp

database.a: employee.o database.o
	ar cr database.a employee.o database.o

clean: 
	rm -rf *.o *.a lab2
