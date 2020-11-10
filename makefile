CC = g++
CFLAGS = -g -Wall -std=c++17
OBJ = pattern_search.o automata.o set_calculator.o
EXEC = pattern_search

all: $(OBJ) 
	$(CC) $(CFLAGS) -o $(EXEC) $^

%.o: %.cc
	$(CC) -c -o $@ $<

run: clean all
	./$(EXEC) abc infile.txt outfile.txt


.PHONY: clean

clean:
	 bash -O extglob -c "rm -vf !(*.cc|*.h|"makefile"|infile.txt|README.md)"