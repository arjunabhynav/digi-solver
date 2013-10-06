CXX = g++

all: main.o helper.o gate.o circuit.o
	g++ -o output main.o helper.o gate.o circuit.o

main.o: main.cpp helper.cpp helper.h gate.cpp gate.h circuit.cpp circuit.h
	g++ -c main.cpp helper.cpp gate.cpp circuit.cpp

helper.o: helper.cpp helper.h
	g++ -c helper.cpp

gate.o: gate.cpp gate.h
	g++ -c gate.cpp

circuit.o: circuit.cpp circuit.h
	g++ -c circuit.cpp

clean: main.o helper.o gate.o circuit.o
	rm *.o
