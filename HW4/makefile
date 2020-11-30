all: Main.o
	g++ -o Main Main.o
Main.o: Main.cpp Lexer.h Type.h Word.h Token.h Num.h Real.h Tag.h
	g++ -c Main.cpp

dep: 
	g++ -M Main.cpp Lexer.h Type.h Word.h Token.h Num.h Real.h Tag.h
	g++ -M -MF dep.d Main.cpp Lexer.h Type.h Word.h Token.h Num.h Real.h Tag.h

clean:
	rm -f *.o Main *.d