CPPFLAGS = -c -Iinc -Wall -pedantic

__start__: projekt_3
		./projekt_3

./projekt_3: obj/main.o obj/board.o obj/game.o
		g++ -Wall -pedantic -o projekt_3 obj/main.o obj/board.o obj/game.o

obj/main.o: src/main.cpp inc/game.hh
		g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/board.o: src/board.cpp inc/board.hh
		g++ ${CPPFLAGS} -o obj/board.o src/board.cpp

obj/game.o: src/game.cpp inc/game.hh inc/board.hh inc/state.hh
		g++ ${CPPFLAGS} -o obj/game.o src/game.cpp

clean:
		rm -f obj/*.o projekt_3