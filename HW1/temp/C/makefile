all:main.c main2.c stack.c
	gcc -c main.c main2.c stack.c
	gcc -o main main.o stack.o
	gcc -o main2 main2.o stack.o
dep:
	gcc -M main.c main2.c stack.c
clean:
	rm -f main main2 main.o main2.o stack.o
