CC = gcc
CFLAGS = -Wall
EXE = tema1
all: clean build run 
build:
	$(CC) *.c -o $(EXE) $(CFLAGS)
run:
	./$(EXE)
clean:
	rm -f *~ *.out $(EXE)
