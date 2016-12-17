
OBJ=main.o server.o

# g++ optimalization
OPT=-O2

program: ${OBJ}
	g++ ${OBJ} -o server ${OPT}

server: server.h server.cpp
	g++ server.cpp -c ${OPT}

main: main.cpp
	g++ main.cpp -c ${OPT}

clean:
	rm -f *.o server
