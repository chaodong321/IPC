#ifndef _UTIL_SEM_H_
#define _UTIL_SEM_H_

#ifdef __plusplus
extern "C"{
#endif

#include <sys/types.h>

typedef int sem_t;
union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
}arg;

sem_t create_sem(key_t key, int value);
void destroy_sem(sem_t semid);
int sem_p(sem_t semid);
int sem_v(sem_t semid);
void set_value_sem(sem_t semid, int value);
int get_value_sem(sem_t semid);

#ifdef __plusplus
}
#endif

#endif
