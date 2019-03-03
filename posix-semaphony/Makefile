.PHONY: all clean

CC = gcc
CCFLAGS = -g
LIBS = -lrt

all:
	$(CC) $(CCFLAGS) -o semaphore_post semaphore_post.c $(LIBS)
	$(CC) $(CCFLAGS) -o semaphore_wait semaphore_wait.c $(LIBS)

clean:
	rm semaphore_post semaphore_wait -f
