GDALL = -L/usr/lib/ -lgdal
GDALI = -I/usr/include/gdal

main: main.o
	g++ main.o -o data_reader $(GDALL)

main.o: main.cpp
	g++ main.cpp -c $(GDALI)

clean:
	rm -f *.o data_reader
