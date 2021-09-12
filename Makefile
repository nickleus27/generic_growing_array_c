test : main.o gen_vect.o
	cc -o test main.o gen_vect.o

main.o : main.c gen_vect.h
	cc -c main.c

gen_vect.o : gen_vect.c gen_vect.h
	cc -c gen_vect.c

clean :
	rm test main.o gen_vect.o
