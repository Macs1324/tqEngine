CC = clang++

INCLUDEFLAGS = -Ilib/glfw/include -Ilib/glew/include -Isrc/modules -Ilib/glm/glm
LDFLAGS = -lm -lGL -lX11 -lpthread -ldl
LIBS = lib/glew/lib/libGLEW.a lib/glfw/src/libglfw3.a
BIN = bin/game.x86_64
MAIN = src/main.cpp

SRC = $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp) $(wildcard src/**/**/**/*.cpp)
OBJ = $(SRC:.cpp=.o)

.PHONY: all run

all: game

run: game
	printf "Starting program...\n\n\n\n\n\n\n"
	./$(BIN)

game: $(OBJ)
	$(CC) $(MAIN) $(LDFLAGS) $(INCLUDEFLAGS) $(LIBS) $^ -o $(BIN)
	$(MAKE) clean

%.o: %.cpp
	$(CC) $(INCLUDEFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)