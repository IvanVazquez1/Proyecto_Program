
bin/compuertasproyecto : src/compuertas2.0.cpp
	g++ -o bin/compuertasproyecto src/compuertas2.0.cpp -Iinclude

run : bin/compuertasproyecto.exe
	./bin/compuertasproyecto.exe