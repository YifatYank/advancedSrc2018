# yankovy: Yifat Yankocivh, 204709224, recitation group 06
# bagnosh: Shoham Bar-Gad, 315706614, recitation group 04

all: serverMain.cpp ClientHandler.o CommandsManager.o GameMaster.o JoinCommand.o ListCommand.o Server.o SocketManager.o StartCommand.o ThreadManager.o
	g++ serverMain.cpp ClientHandler.o CommandsManager.o GameMaster.o JoinCommand.o ListCommand.o Server.o SocketManager.o StartCommand.o ThreadManager.o -std=c++98 -o server -pthread

ClientHandler.o: ClientHandler.cpp ClientHandler.h
	g++ -c ClientHandler.cpp ClientHandler.h -std=c++98 -pthread

CommandsManager.o: CommandsManager.cpp CommandsManager.h
	g++ -c CommandsManager.cpp CommandsManager.h -std=c++98 -pthread

GameMaster.o: GameMaster.cpp GameMaster.h
	g++ -c GameMaster.cpp GameMaster.h -std=c++98 -pthread

JoinCommand.o: JoinCommand.cpp JoinCommand.h Command.h
	g++ -c JoinCommand.cpp JoinCommand.h -std=c++98 -pthread

ListCommand.o: ListCommand.cpp ListCommand.h Command.h
	g++ -c ListCommand.cpp ListCommand.h -std=c++98 -pthread

Server.o: Server.cpp Server.h
	g++ -c Server.cpp Server.h -std=c++98 -pthread

SocketManager.o: SocketManager.cpp SocketManager.h
	g++ -c SocketManager.cpp SocketManager.h -std=c++98 -pthread

StartCommand.o: StartCommand.cpp StartCommand.h Command.h
	g++ -c StartCommand.cpp StartCommand.h -std=c++98 -pthread

ThreadManager.o: ThreadManager.cpp ThreadManager.h
	g++ -c ThreadManager.cpp ThreadManager.h -std=c++98 -pthread
