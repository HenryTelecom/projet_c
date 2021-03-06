CC=gcc
FLAGS=-Wall -pedantic -pedantic-errors -ansi
FRAMEWORKS=-framework SDL2 -framework SDL2_mixer
FRAMEWORKS_LINUX=-lSDL2 -lSDL2_ttf -lSDL2_mixer
SOURCE=./main.c
LIBS=window.c damier.c pion.c SDLS.c son.c
EXEC=./main.out

all: compile launch clean

mac: compile_mac launch clean

linux: compile_linux launch clean

compile_mac:
	$(CC) $(FRAMEWORKS) $(SOURCE) $(LIBS) $(FLAGS) -o $(EXEC)

compile_linux:
	$(CC) $(SOURCE) $(FRAMEWORKS_LINUX) $(LIBS) $(FLAGS) -o $(EXEC)

compile:
	$(CC) $(FRAMEWORKS) $(SOURCE) $(LIBS) $(FLAGS) -o $(EXEC)

launch:
	$(info ${\n}---------------------------------------${\n})
	$(EXEC)

clean:
	$(info ${\n}${\n}---------------------------------------${\n})
	rm *.out
