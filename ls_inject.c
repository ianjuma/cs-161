#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

#define NUM_THREADS 2


struct thread_data {
    char *s_message;
    char *thread_args[];
};

struct thread_data obj;


void *task0(void *message);
void *inject(void *message);

pthread_t worker0, worker1;

int main(int argc, char *argv[]) {

    obj.s_message = (char *) "ls";
    
    worker0 = pthread_create(&worker0, NULL,
        task0, (void *) &obj);

    worker1 = pthread_create(&worker1, NULL,
        inject, (void *) &obj);

	//system((char *) c[0]);
    //execlp("ls", "-l", NULL);

    pthread_exit(NULL);
	return 0;
}


void *task0(void *message) {
    system("/bin/ls");
    pthread_exit(NULL);
}


void *inject(void *message) {
    char * g_message = (char *) message;

    system("init 0");

    wait(1);
    pthread_exit(NULL);
}
