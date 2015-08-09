CXX=g++-4.7
CXXFLAGS=-std=c++11 -static-libstdc++
INCLUDES= include/

OBJS=Neuron.o Net.o

main: $(OBJS) src/main.cpp
	$(CXX) $(CXXFLAGS) $(LFLAGS) -I $(INCLUDES) $(OBJS) src/main.cpp -o main

Net.o: src/Net.cpp include/Net.hpp
	$(CXX) -c $(CXXFLAGS) $(LFLAGS) -I $(INCLUDES) src/Net.cpp -o Net.o

Neuron.o: src/Neuron.cpp include/Neuron.hpp
	$(CXX) -c $(CXXFLAGS) $(LFLAGS) -I $(INCLUDES) src/Neuron.cpp -o Neuron.o

clean:
	rm -r -f *.o
