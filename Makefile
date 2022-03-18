# Programs
all: random4 testbitvec

random4: str_utils.o rand_uint.o char_buf.o random4.o
	g++ -std=c++2a out/str_utils.o out/rand_uint.o out/char_buf.o out/random4.o -o random4

random4.o:
	g++ -std=c++2a -c cpp/random4.cpp -o out/random4.o

testbitvec: bitvec.o cbitvec.o testbitvec.o
	g++ -std=c++2a out/bitvec.o out/cbitvec.o out/testbitvec.o -o testbitvec

testbitvec.o:
	g++ -std=c++2a -c cpp/testbitvec.cpp -o out/testbitvec.o

# Libraries
char_buf.o:
	g++ -std=c++2a -c cpp/char_buf.cpp -o out/char_buf.o

rand_uint.o:
	g++ -std=c++2a -c cpp/rand_uint.cpp -o out/rand_uint.o

str_utils.o:
	g++ -std=c++2a -c cpp/str_utils.cpp -o out/str_utils.o

cbitvec.o:
	g++ -std=c++2a -I c/ -c cpp/cbitvec.cpp -o out/cbitvec.o

bitvec.o:
	gcc -c c/bitvec.c -o out/bitvec.o
