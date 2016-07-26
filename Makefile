CXX=g++
CXXFLAGS=-MMD -Wall -g
OBJECTS=main.o controller.o board.o game.o player.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=tictactoe

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
