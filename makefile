CC = g++
FLAG = -Wall

all: bin/project

bin/project: build/main.o build/file.o build/rabin_karp.o build/boyermoore.o build/knuthmorrispratt.o
		$(CC) $(FLAG) build/main.o build/file.o build/rabin_karp.o build/boyermoore.o build/knuthmorrispratt.o -o bin/project -lm
build/main.o: src/main.cpp
		$(CC) $(FLAG) -c src/main.cpp -o build/main.o
build/file.o: src/file.cpp
		$(CC) $(FLAG) -c src/file.cpp -o build/file.o 
build/rabin_karp.o: src/rabin_karp.cpp
		$(CC) $(FLAG) -c src/rabin_karp.cpp -o build/rabin_karp.o -lm 
build/boyermoore.o: src/boyermoore.cpp
		$(CC) $(FLAG) -c src/boyermoore.cpp -o build/boyermoore.o 
build/knuthmorrispratt.o: src/knuthmorrispratt.cpp
		$(CC) $(FLAG) -c src/knuthmorrispratt.cpp -o build/knuthmorrispratt.o 

dir:
		mkdir build
		mkdir bin
		
clean:
		rm build/*.o
