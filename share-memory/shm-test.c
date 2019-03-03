#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#include "util-sem.h"

#define SHM_PATH "/ipc/sem"

static char msg[] = "hello world, share memory\n";

int main(int argc, char **argv)
{
	key_t key = ftok(SHM_PATH, 'a');

	int shmid = shmget(key, 1024, IPC_CREAT|0604);

	int semid = create_sem(key, 0);

	struct shmid_ds buf;
	
	char *shms, *shmc;
	pid_t p = fork();
	if(p > 0){
		shms = (char*)shmat(shmid, 0, 0);
		printf("server share memory addr:%p\n", shms);

		sleep(3);

		memcpy(shms, msg, strlen(msg)+1);

		sem_v(semid);

		shmdt(shms);

		sleep(1);
		destroy_sem(semid);
		if(shmctl(shmid, IPC_RMID, &buf) == -1){
			printf("server free share memory error, errno:%d, errno string:%s\n", errno, strerror(errno));
		}
	}
	else if(p == 0){
		shmc = (char*)shmat(shmid, 0, 0);
		printf("client share memory addr:%p\n", shmc);
		sem_p(semid);

		printf("clinet share memory value:%s\n", shmc);
		shmdt(shmc);

		sleep(2);
		if(shmctl(shmid, IPC_RMID, &buf) == -1){
			printf("client free share memory error, errno:%d, errno string:%s\n", errno, strerror(errno));
		}
	}
	else{
		printf("fork error\n");
	}
	return 0;
}
