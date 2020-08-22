
Random.so: Random.c Random.h
	gcc -Wall -fPIC -c -O2 Random.c
	gcc -shared Random.o -o Random.so -I/usr/local/include -lgsl -lgslcblas -lm

Example: Example.c Random.so
	gcc Example.c ./Random.so -o Example

clean:
	rm -f Random.o Random.so Example

