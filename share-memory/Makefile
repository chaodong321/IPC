.PHONY: all clean

CC = gcc
CFLAGS = -g -Wall
INC = -I./
LIBS =

OBJ = util-sem.o util-shm.o

SEM_TEST = sem-test
SEM_P = sem-p
SEM_V = sem-v
SHM_TEST = shm-test
SHM_WRITE = shm-write
SHM_READ = shm-read

all: $(SEM_TEST) $(SHM_TEST) $(SHM_WRITE) $(SHM_READ) $(SEM_P) $(SEM_V)

$(SEM_TEST):$(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) sem-test.c -o $@ $(LIBS)

$(SEM_P):$(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) sem-p.c -o $@ $(LIBS)

$(SEM_V):$(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) sem-v.c -o $@ $(LIBS)

$(SHM_TEST):$(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) shm-test.c -o $@ $(LIBS)

$(SHM_WRITE):$(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) shm-write.c -o $@ $(LIBS)

$(SHM_READ):$(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) shm-read.c -o $@ $(LIBS)

$(OBJ):%.o:%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm $(OBJ) $(SEM_TEST) $(SHM_TEST) $(SHM_WRITE) $(SHM_READ) $(SEM_P) $(SEM_V)

