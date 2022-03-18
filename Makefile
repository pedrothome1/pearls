random4: str_utils.o rand_uint.o char_buf.o random4.o
	g++ -std=c++2a out/str_utils.o out/rand_uint.o out/char_buf.o out/random4.o -o random4

random4.o:
	g++ -std=c++2a -c cpp/random4.cpp -o out/random4.o

char_buf.o:
	g++ -std=c++2a -c cpp/char_buf.cpp -o out/char_buf.o

rand_uint.o:
	g++ -std=c++2a -c cpp/rand_uint.cpp -o out/rand_uint.o

str_utils.o:
	g++ -std=c++2a -c cpp/str_utils.cpp -o out/str_utils.o
