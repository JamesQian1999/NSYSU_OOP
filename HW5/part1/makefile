all: test.o
	g++ -o main test.o
Main.o: test.cpp Form.h
	g++ -c test.cpp

dep: 
	g++ -M test.cpp Form.h
	g++ -M -MF dep.d test.cpp Form.h
clean:
	rm -f *.o main *.d