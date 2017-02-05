OBJS = dijkstra.o main.o graph.o node.o data_reader.o
NODEI = -I../node
GRAPHI = -I../graph
DRI = -I../data_reader
GDALL = -L/usr/lib/ -lgdal
GDALI = -I/usr/include/gdal
FLAGS = -g

main: $(OBJS)
	g++ $(OBJS) -o dijsktra $(GDALL) $(FLAGS)

dijkstra.o: dijkstra.h dijkstra.cpp
	g++ dijkstra.cpp -c $(GRAPHI) $(NODEI) $(DRI) $(GDALI) $(FLAGS)

graph.o: ../graph/graph.h ../graph/graph.cpp
	g++ ../graph/graph.cpp -c $(NODEI) $(DRI) $(GDALI)

data_reader.o: ../data_reader/data_reader.h ../data_reader/data_reader.cpp
	g++ ../data_reader/data_reader.cpp -c $(GDALI) $(NODEI)

node.o: ../node/node.hpp ../node/node.cpp
	g++ ../node/node.cpp -c

main.o: main.cpp
	g++ main.cpp -c $(NODEI) $(DRI) $(GDALI) $(GRAPHI) $(FLAGS)

clean:
	rm -f *.o dijkstra
