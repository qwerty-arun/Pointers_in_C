CC=clang
CFLAGS=-I.
DEPS = 
OBJ = program.o 

%.o: %.c $(DEPS)
	$(CC) -c -g -o $@ $< $(CFLAGS)

output: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	rm -rf *.o output
	rm a.out 

run: 
	make && ./output
