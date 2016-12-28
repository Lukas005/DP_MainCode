OBJS = main.o graph.o node.o data_reader.o
NODEI = -I../node
DRI = -I../data_reader
GDALL = -L/usr/lib/ -lgdal
GDALI = -I/usr/include/gdal

main: $(OBJS)
	g++ $(OBJS) -o graph $(GDALL)

graph.o: graph.h graph.cpp
	g++ graph.cpp -c $(NODEI) $(DRI) $(GDALI)

data_reader.o: ../data_reader/data_reader.h ../data_reader/data_reader.cpp
	g++ ../data_reader/data_reader.cpp -c $(GDALI) $(NODEI)

node.o: ../node/node.hpp ../node/node.cpp
	g++ ../node/node.cpp -c

main.o: main.cpp
	g++ main.cpp -c $(NODEI) $(DRI) $(GDALI)

clean:
	rm -f *.o graph
