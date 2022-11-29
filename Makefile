OBJS = main.c game.c gfx.c

CC = gcc

COMPILER_FLAGS = -Wall -Werror -pedantic

LINKER_FLAGS = -lSDL2 -lSDL2_image -lm

OBJ_NAME = main

	
all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run: $(OBJS)
	./$(OBJ_NAME)

clean:
	rm -rf ./$(OBJ_NAME)