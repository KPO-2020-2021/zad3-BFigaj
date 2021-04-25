#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: obroty_2D
	./obroty_2D

obroty_2D: obj obj/main.o obj/Prostokat.o obj/Macierz2x2.o obj/Wektor2D.o\
           obj/lacze_do_gnuplota.o
	g++ -Wall -pedantic -std=c++0x -o obroty_2D obj/main.o obj/Wektor2D.o\
                        obj/Macierz2x2.o obj/Prostokat.o obj/lacze_do_gnuplota.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Prostokat.hh inc/Macierz2x2.hh inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostokat.o: src/Prostokat.cpp inc/Prostokat.hh
	g++ -c ${CXXFLAGS} -o obj/Prostokat.o src/Prostokat.cpp

obj/Macierz2x2.o: src/Macierz2x2.cpp inc/Macierz2x2.hh 
	g++ -c ${CXXFLAGS} -o obj/Macierz2x2.o src/Macierz2x2.cpp

obj/Wektor2D.o: src/Wektor2D.cpp inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor2D.o src/Wektor2D.cpp
	
./tests/bin/test_1: ./tests/bin ./obj/Prostokat.o 
	g++ -o ./tests/bin/test_1 ${CXXFLAGS} -I./tests/doctest ./tests/test1.cpp ./obj/Prostokat.o ./obj/Wektor2D.o ./obj/Macierz2x2.o

./tests/bin/test_2: ./tests/bin ./obj/Prostokat.o 
	g++ -o ./tests/bin/test_2 ${CXXFLAGS} -I./tests/doctest ./tests/test2.cpp ./obj/Wektor2D.o ./obj/Macierz2x2.o

./tests/bin/test_3: ./tests/bin ./obj/Prostokat.o 
	g++ -o ./tests/bin/test_3 ${CXXFLAGS} -I./tests/doctest ./tests/test3.cpp ./obj/Macierz2x2.o ./obj/Wektor2D.o


./tests/bin:
	mkdir ./tests/bin

test:  ./tests/bin/test_1 ./tests/bin/test_2 ./tests/bin/test_3
	./tests/bin/test_1 
	./tests/bin/test_2
	./tests/bin/test_3

clean:
	rm -f obj/*.o obroty_2D
