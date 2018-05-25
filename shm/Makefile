.PHONY:all
all:writer reader

writer:writer.c comm.c
	gcc -o $@ $^

reader:reader.c comm.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm writer reader
