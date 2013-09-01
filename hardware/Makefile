CC=gcc
CFLAGS=-I.
OBJ = MMU.o z80.o 

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

crossgb: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) 

.PHONY: clean

clean:
	rm -f *.o 