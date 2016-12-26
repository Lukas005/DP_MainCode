OBJS = main.o graph.o node.o

NODEI = -I../node

main: $(OBJS)
	g++ $(OBJS) -o graph

main.o: main.cpp
		g++ main.cpp -c $(NODEI)

graph.o: graph.h graph.cpp
	g++ graph.cpp -c $(NODEI)

node.o: ../node/node.hpp ../node/node.cpp
	g++ ../node/node.cpp -c

clean:
	rm -f *.o graph
