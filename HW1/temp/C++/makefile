all: main.cpp main2.cpp stack.cpp
	g++ -c main.cpp main2.cpp stack.cpp
	g++ -o main main.o stack.o
	g++ -o main2 main2.o stack.o
dep: 
	g++ -M main.cpp main2.cpp stack.cpp
	g++ -M -MF dep.d main.cpp main2.cpp stack.cpp
clean:
	rm -f main main2 main.o main2.o stack.o dep.d
