CXX=g++
CXXFLAGS=-std=c++11 -static-libstdc++
LFLAGS=-I./include/ -lpthread -pthread -I./lib/include/ -I./

OBJS=Neuron.o Net.o Logger.o

main: $(OBJS) src/main.cpp
	$(CXX) $(CXXFLAGS) $(LFLAGS) $(OBJS) src/main.cpp -o main

Net.o: src/Net.cpp include/Net.hpp
	$(CXX) -c $(CXXFLAGS) $(LFLAGS) src/Net.cpp -o Net.o

Neuron.o: src/Neuron.cpp include/Neuron.hpp
	$(CXX) -c $(CXXFLAGS) $(LFLAGS) src/Neuron.cpp -o Neuron.o

Logger.o: lib/src/Logger.cpp lib/include/Logger.hpp
	$(CXX) -c $(CXXFLAGS) $(LFLAGS) lib/src/Logger.cpp -o Logger.o

clean:
	rm -r -f *.o
