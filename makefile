CC=gcc
FLAGS=-Wall -pedantic -pedantic-errors -ansi
FRAMEWORKS=-L/Library/Frameworks -framework SDL2
FRAMEWORKS_LINUX=-I/usr/include/SDL/ -L/usr/lib -lSDL2
SOURCE=./main.c
LIBS=window.c damier.c
EXEC=./main.out

all: compile launch clean

mac: compile_mac launch clean

linux: compile_linux launch clean

compile_mac:
	$(CC) $(FRAMEWORKS) $(SOURCE) $(LIBS) $(FLAGS) -o $(EXEC)

compile_linux:
	$(CC) $(FRAMEWORKS_LINUX) $(SOURCE) $(LIBS) $(FLAGS) -o $(EXEC)

compile:
	$(CC) $(FRAMEWORKS) $(SOURCE) $(LIBS) $(FLAGS) -o $(EXEC)

launch:
	$(info ${\n}---------------------------------------${\n})
	$(EXEC)

clean:
	$(info ${\n}${\n}---------------------------------------${\n})
	rm *.out
