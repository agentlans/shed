
Projections.so: Projections.cpp
	g++ -c -fPIC -O3 Projections.cpp
	g++ -shared Projections.o -o Projections.so -larmadillo

Example: Example.cpp Projections.so
	g++ Example.cpp ./Projections.so -o Example

clean:
	rm -f Projections.so Projections.o Example

