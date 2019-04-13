
.PHONY:a.out clean




a.out:main.cpp game.h car.o module1.o module2.o db.o
	g++ -o a.out main.cpp db.o car.o module1.o module2.o

module1.o:module1.cpp
	g++ -c module1.cpp

module2.o:module2.cpp
	g++ -c module2.cpp

car.o:car.cpp car.h game.h
	g++ -c car.cpp

db.o:db.cpp game.h
	g++ -c db.cpp

clean:
	rm -rf a.out *.o

