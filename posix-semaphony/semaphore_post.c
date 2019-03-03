#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

#define SEM_NAME "sem_test"

int main(int argc, char **argv)
{
	sem_t *sem_test;
	sem_test = sem_open(SEM_NAME, O_CREAT, 0644, 1);
	if(SEM_FAILED == sem_test){
		perror("sem_open");
	}

	int i = 0;
	while(1){
		int sem_value;
		if(sem_getvalue(sem_test, &sem_value) == 0){
			printf("sem_value:%d\n", sem_value);
			if(sem_value < 1){
				printf("sem post, time: %d\n", i++);
				sem_post(sem_test);
			}
		}
		sleep(2);
	}
	sem_unlink(SEM_NAME);
	sem_close(sem_test);
	return 0;
}
