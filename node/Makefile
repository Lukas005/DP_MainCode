node_test: main.cpp node.o
	g++ node.o main.cpp -o node_test

node: node.hpp node.cpp
	g++ node.cpp -c

clean:
	rm -f *.o node_test
