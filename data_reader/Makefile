GDALL = -L/usr/lib/ -lgdal
GDALI = -I/usr/include/gdal
OBJS = main.o data_reader.o node.o

NODEI = -I../node

main: $(OBJS)
	g++ main.o data_reader.o node.o -o data_reader $(GDALL)

main.o: main.cpp
	g++ main.cpp -c $(GDALI) $(NODEI)

data_reader.o: data_reader.h data_reader.cpp
	g++ data_reader.cpp -c $(GDALI) $(NODEI)

node.o: ../node/node.hpp ../node/node.cpp
	g++ ../node/node.cpp -c

clean:
	rm -f *.o data_reader
