CXX = g++
CXXFLAGS = -Wall -std=c++14
LDFLAGS = -lavcodec -lavutil -lavformat

all: main

main: main.o Encoder.o ROIManager.o
	$(CXX) -o $@ $^ $(LDFLAGS)

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Encoder.o: src/Encoder.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

ROIManager.o: src/ROIManager.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o main