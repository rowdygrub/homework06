main:  main.o publication.o library.o
	g++ -std=c++11 -o main main.o publication.o library.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main.o: main.cpp
	g++ -std=c++11 -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
publication.o: publication.cpp publication.h
	g++ -std=c++11 -c publication.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
library.o: library.cpp library.h
	g++ -std=c++11 -c library.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
clean:
	-rm -f *.o main
