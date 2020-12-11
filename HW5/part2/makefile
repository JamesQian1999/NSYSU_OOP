all: test.o Trace.o
	g++ -o main test.o Trace.o
test.o: test.cpp Vector.h
	g++ -c test.cpp
Trace.o: Trace.cpp Trace.h
	g++ -c Trace.cpp

dep: 
	g++ -M test.cpp Trace.cpp Trace.h Vector.h
	g++ -M -MF dep.d test.cpp Trace.cpp Trace.h Vector.h

clean:
	rm -f *.o main *.d