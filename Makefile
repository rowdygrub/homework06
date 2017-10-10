main:  main.o publication.o library.o main_window.o controller.o
	g++ -std=c++11 -o main main.o publication.o library.o main_window.o controller.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
	./main

controller.o: controller.cpp
	g++ -std=c++11 -c controller.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main_window.o: main_window.cpp main_window.h
	g++ -std=c++11 -c main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main.o: main.cpp
	g++ -std=c++11 -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
publication.o: publication.cpp publication.h
	g++ -std=c++11 -c publication.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
library.o: library.cpp library.h
	g++ -std=c++11 -c library.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
clean:
	-rm -f *.o main
