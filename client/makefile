# yankovy: Yifat Yankocivh, 204709224, recitation group 06
# bagnosh: Shoham Bar-Gad, 315706614, recitation group 04

all: ex1.cpp AIPlayer.o Board.o ClassicLogic.o Client.o ClientCommandsManager.o ClientJoinCommand.o ClientListCommand.o ClientStartCommand.o ConsolePlayer.o ConsuleDisplay.o GameManager.o Point.o RemotePlayer.o
	g++ ex1.cpp AIPlayer.o Board.o ClassicLogic.o Client.o ClientCommandsManager.o ClientJoinCommand.o ClientListCommand.o ClientStartCommand.o ConsolePlayer.o ConsuleDisplay.o GameManager.o Point.o RemotePlayer.o -std=c++98 -o client -pthread

AIPlayer.o: AIPlayer.cpp AIPlayer.h Player.h
	g++ -c  AIPlayer.cpp AIPlayer.h -std=c++98 -pthread

Board.o: Board.cpp Board.h
	g++ -c  Board.cpp Board.h -std=c++98 -pthread

ClassicLogic.o: ClassicLogic.cpp ClassicLogic.h GameLogic.h
	g++ -c  ClassicLogic.cpp ClassicLogic.h -std=c++98 -pthread

Client.o: Client.cpp Client.h
	g++ -c  Client.cpp Client.h -std=c++98 -pthread

ClientCommandsManager.o: ClientCommandsManager.cpp ClientCommandsManager.h
	g++ -c ClientCommandsManager.cpp ClientCommandsManager.h -std=c++98 -pthread

ClientJoinCommand.o: ClientJoinCommand.cpp ClientJoinCommand.h ClientCommand.h
	g++ -c ClientJoinCommand.cpp ClientJoinCommand.h -std=c++98 -pthread

ClientListCommand.o: ClientListCommand.cpp ClientListCommand.h ClientCommand.h
	g++ -c ClientListCommand.cpp ClientListCommand.h -std=c++98 -pthread

ClientStartCommand.o: ClientStartCommand.cpp ClientStartCommand.h ClientCommand.h
	g++ -c ClientStartCommand.cpp ClientStartCommand.h -std=c++98 -pthread

ConsolePlayer.o: ConsolePlayer.cpp ConsolePlayer.h Player.h
	g++ -c  ConsolePlayer.cpp ConsolePlayer.h -std=c++98 -pthread

ConsuleDisplay.o: ConsuleDisplay.cpp ConsuleDisplay.h GameDisplay.h
	g++ -c  ConsuleDisplay.cpp ConsuleDisplay.h -std=c++98 -pthread

GameManager.o: GameManager.cpp GameManager.h
	g++ -c  GameManager.cpp GameManager.h -std=c++98 -pthread

Point.o: Point.cpp Point.h
	g++ -c  Point.cpp Point.h -std=c++98 -pthread

RemotePlayer.o: RemotePlayer.cpp RemotePlayer.h
	g++ -c  RemotePlayer.cpp RemotePlayer.h -std=c++98 -pthread
