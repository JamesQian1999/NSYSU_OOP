all: main.o mytar.o
	g++ -o mytar main.o mytar.o
main.o: main.cpp
	g++ -c main.cpp
MyTar.o: mytar.cpp mytar.h
	g++ -c mytar.cpp

dep: 
	g++ -M main.cpp mytar.cpp mytar.h
	g++ -M -MF dep.d main.cpp mytar.cpp mytar.h 

clean:
	rm -f *.o mytar *.d
