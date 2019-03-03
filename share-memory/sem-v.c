#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>

#include "util-sem.h"

#define SEM_PATH "/ipc/sem"

int main(int argc, char **argv)
{
	key_t key = ftok(SEM_PATH, 'a');
	printf("key:%d\n", key);
	if(-1 == key){
		printf("can't ftok key\n");
		return 0;
	}
	
	sem_t semid = create_sem(key, 0);

	while(1){
		sleep(3);
		printf("sem v, free sourse\n");
		sem_v(semid);
	}

	int value = get_value_sem(semid);
	printf("semaphore value: %d\n", value);

	//destroy_sem(semid);
	
	return 0;
}

