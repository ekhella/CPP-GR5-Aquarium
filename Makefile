main : main.cpp Aquarium.o Bestiole.o Milieu.o
	g++ -Wall -std=c++14 -o main main.cpp Aquarium.o Milieu.o Bestiole.o -I . -I/opt/x11/include -lX11 -lpthread -L/opt/x11/lib

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I . -I/opt/x11/include


Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I . -I/opt/x11/include

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I . -I/opt/x11/include

clean:
	rm -rf *.o main

