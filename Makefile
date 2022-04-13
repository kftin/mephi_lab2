CC = g++

all:main

main:main.o f_lab2_cl.o
	$(CC) main.o f_lab2_cl.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

f_lab2_cl.o: f_lab2_cl.cpp
	$(CC) -c f_lab2_cl.cpp

clean:
	rm -rf *.o main

