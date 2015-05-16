LDFLAGS := -lpthread -lgtest -lgtest_main -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS= -std=c++14 -g -Wall

MAIN= bin/main.o
OBJ= bin/Node.o bin/Grid.o bin/GridAsciiUtils.o
INC= -I include
TEST= tests/tests.grid.o

all: netcore test

netcore: $(OBJ) $(MAIN)
	g++ $(OBJ) $(MAIN) $(INC) $(LDFLAGS) $(CFLAGS) -o netcore

bin/%.o: src/%.cpp
	g++ -c $(CFLAGS) $(INC) $< -o $@

tests/%.o: tests/%.cpp
	g++ -c $(CFLAGS) $(INC) $< -o $@

clean:
	rm -r bin/*.o tests/*.o netcore test

test: $(TEST) $(OBJ)
	g++ $(TEST) $(OBJ) $(INC) $(LDFLAGS) $(CFLAGS) -o test
 
