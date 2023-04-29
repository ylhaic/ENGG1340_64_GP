# Variables
CXX = g++
FLAGS = -pedantic-errors -std=c++11
OBJ_FILES = text-based-game.o game1.o game2.o game4.o game5.o introduction.o room1.o room2.o room3.o room4.o room5.o room6.o room7.o room8.o win.o
TARGET = game

# Default rule (all)
all: $(TARGET)

# Rule for linking object files to create the executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(FLAGS) $^ -o $@

# Rule for compiling each source file into an object file
text-based-game.o: text-based-game.cpp
	$(CXX) $(FLAGS) -c $< -o $@

game1.o: game1.cpp
	$(CXX) $(FLAGS) -c $< -o $@

game2.o: game2.cpp
	$(CXX) $(FLAGS) -c $< -o $@

game4.o: game4.cpp
	$(CXX) $(FLAGS) -c $< -o $@

game5.o: game5.cpp
	$(CXX) $(FLAGS) -c $< -o $@

introduction.o: introduction.cpp introduction.h
	$(CXX) $(FLAGS) -c $< -o $@

room1.o: room1.cpp room1.h
	$(CXX) $(FLAGS) -c $< -o $@

room2.o: room2.cpp room2.h
	$(CXX) $(FLAGS) -c $< -o $@

room3.o: room3.cpp room3.h
	$(CXX) $(FLAGS) -c $< -o $@

room4.o: room4.cpp room4.h
	$(CXX) $(FLAGS) -c $< -o $@
	
room5.o: room5.cpp room5.h
	$(CXX) $(FLAGS) -c $< -o $@

room6.o: room6.cpp room6.h
	$(CXX) $(FLAGS) -c $< -o $@

room7.o: room7.cpp room7.h
	$(CXX) $(FLAGS) -c $< -o $@

room8.o: room8.cpp room8.h
	$(CXX) $(FLAGS) -c $< -o $@

win.o: win.cpp win.h
	$(CXX) $(FLAGS) -c $< -o $@
# Rule for cleaning the project
clean:
	rm -f $(TARGET) $(OBJ_FILES) game.tgz

# Rule for creating a tarball of the source files
tar:
	tar -czvf game.tgz *.cpp *.h Makefile

.PHONY: all clean tar