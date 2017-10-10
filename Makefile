CXXFLAGS = --std=c++11

all: main

debug: CXXFLAGS += -g
debug: main

main:  main.o publication.o library.o main_window.o controller.o
	$(CXX) $(CXXFLAGS) -o main main.o publication.o library.o main_window.o controller.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
	./main

controller.o: controller.cpp controller.h
	$(CXX) $(CXXFLAGS) -c controller.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main_window.o: main_window.cpp main_window.h
	$(CXX) $(CXXFLAGS) -c main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

publication.o: publication.cpp publication.h
	$(CXX) $(CXXFLAGS) -c publication.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

library.o: library.cpp library.h
	$(CXX) $(CXXFLAGS) -c library.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

clean:
	-rm -f *.o main
