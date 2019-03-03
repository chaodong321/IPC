#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/sem.h>

#include "util-sem.h"

sem_t create_sem(key_t key, int value)
{
	union semun sem;
	sem.val = value;

	sem_t semid = semget(key, 1, IPC_CREAT|0666);		//参数2表示资源个数，必须大于0，信号量有多个，是个数组
	if(-1 == semid){
		printf("create semaphore error, err no:%d, err string:%s\n", errno, strerror(errno));
		return -1;
	}

	semctl(semid, 0, SETVAL, sem);

	return semid;
}

void destroy_sem(sem_t semid)
{
	union semun sem;
	sem.val = 0;

	semctl(semid, 0, IPC_RMID, sem);		//参数二表示信号量的序号（数组从0开始）
}

int sem_p(sem_t semid)				//请求资源
{
	struct sembuf sops = { 0, -1, SEM_UNDO };		//使用IPC_NOWAIT，将不会阻塞

	return (semop(semid, &sops, 1))	;
}

int sem_v(sem_t semid)				//释放资源
{
	struct sembuf sops = { 0, +1, IPC_NOWAIT };

	return (semop(semid, &sops, 1));
}

void set_value_sem(sem_t semid, int value)
{
	union semun sem;
	sem.val = value;
	semctl(semid, 0, SETVAL, sem);
}

int get_value_sem(sem_t semid)
{
	union semun sem;
	return semctl(semid, 0, GETVAL, sem);
}

