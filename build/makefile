COMPILER=g++

BISHOP=../resources/bishop.cpp
CHESSBOARD=../resources/chessboard.cpp
EVENTHANDLER=../resources/eventhandler.cpp
KING=../resources/king.cpp
KNIGHT=../resources/knight.cpp
MAIN=../resources/main.cpp
MOVEMENT=../resources/movement.cpp
PAWN=../resources/pawn.cpp
PIECE=../resources/piece.cpp
QUEEN=../resources/queen.cpp
ROOK=../resources/rook.cpp
STARTMENU=../resources/startmenu.cpp



all: compile link

compile:
	$(COMPILER) -I ../src/include -c $(BISHOP) $(CHESSBOARD) $(EVENTHANDLER) $(KING) $(KNIGHT) $(MAIN) $(MOVEMENT) $(PAWN) $(PIECE) $(QUEEN) $(ROOK) $(STARTMENU)

link:
	$(COMPILER) bishop.o chessboard.o eventhandler.o king.o knight.o main.o movement.o pawn.o piece.o queen.o rook.o startmenu.o -o main -L ../src/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio