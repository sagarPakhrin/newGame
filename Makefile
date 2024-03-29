# this target will compile all the files
CFLAGS = -c -Wall
src = src
CC = g++

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

TARGET: main.o StateMachine.o Kunai.o AssetManager.o InputManager.o Game.o \
		SplashState.o MainMenuState.o GameState.o Character.o Animation.o Ground.o \
		Collider.o Enemy.o
	$(CC) StateMachine.o Game.o Ground.o Kunai.o Collider.o InputManager.o \
			AssetManager.o Enemy.o SplashState.o MainMenuState.o GameState.o Character.o \
			Animation.o main.o -o main $(LIBS)

main.o: src/main.cpp $(src)/DEFINATIONS.hpp
	$(CC) $(CFLAGS) $(src)/main.cpp

StateMachine.o: $(src)/StateMachine.cpp $(src)/StateMachine.hpp
	$(CC) $(CFLAGS) $(src)/StateMachine.cpp

AssetManager.o: $(src)/AssetManager.cpp $(src)/AssetManager.hpp
	$(CC) $(CFLAGS) $(src)/AssetManager.cpp

InputManager.o: $(src)/InputManager.cpp $(src)/InputManager.hpp
	$(CC) $(CFLAGS) $(src)/InputManager.cpp

Game.o: $(src)/Game.cpp $(src)/Game.hpp
	$(CC) $(CFLAGS) $(src)/Game.cpp

SplashState.o: $(src)/SplashState.hpp $(src)/SplashState.cpp $(src)/DEFINATIONS.hpp
	$(CC) $(CFLAGS) $(src)/SplashState.cpp

MainMenuState.o: $(src)/MainMenuState.hpp $(src)/MainMenuState.cpp $(src)/DEFINATIONS.hpp
	$(CC) $(CFLAGS) $(src)/MainMenuState.cpp

GameState.o: $(src)/GameState.hpp $(src)/GameState.cpp $(src)/Character.hpp $(src)/Collider.hpp $(src)/DEFINATIONS.hpp
	$(CC) $(CFLAGS) $(src)/GameState.cpp

Character.o: $(src)/Character.hpp $(src)/Character.cpp $(src)/Animation.hpp $(src)/DEFINATIONS.hpp
	$(CC) $(CFLAGS) $(src)/Character.cpp

Animation.o: $(src)/Animation.hpp $(src)/Animation.cpp $(src)/DEFINATIONS.hpp
	$(CC) $(CFLAGS) $(src)/Animation.cpp

Ground.o: $(src)/Ground.hpp $(src)/Ground.cpp $(src)/DEFINATIONS.hpp
	$(CC) $(CFLAGS) $(src)/Ground.cpp

Collider.o: $(src)/Collider.hpp $(src)/Collider.cpp
	$(CC) $(CFLAGS) $(src)/Collider.cpp

Kunai.o: $(src)/Kunai.hpp $(src)/Kunai.cpp
	$(CC) $(CFLAGS) $(src)/Kunai.cpp

Enemy.o: $(src)/Enemy.hpp $(src)/Enemy.cpp
	$(CC) $(CFLAGS) $(src)/Enemy.cpp

clean:
	rm -f *.o main
