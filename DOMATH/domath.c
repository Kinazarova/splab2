#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char** argv){
	if (argc<3) {
		printf("To fev args.\n");
		exit(1);
	}
	pid_t r4 = fork();
	if(r4 == 0){
		int t = atoi(argv[2]);
		int y = atoi(argv[1]);
			printf("CHILD_4: %d / %d = %d\n",y,t,y/t);
		exit(0);
	}
	pid_t r3 = fork();
	if(r3 == 0){
		int t = atoi(argv[2]);
		int y = atoi(argv[1]);
			printf("CHILD_3: %d * %d = %d\n",y,t,y*t);
		exit(0);
	}

	pid_t r2 = fork();
	if(r2 == 0){
		int t = atoi(argv[2]);
		int y = atoi(argv[1]);
			printf("CHILD_2: %d - %d = %d\n",y,t,y-t);
		exit(0);
	}
	pid_t r1 = fork();

	if(r1 == 0){
		int t = atoi(argv[2]);
		int y = atoi(argv[1]);
			printf("CHILD_1: %d + %d = %d\n",y,t,y+t);
		exit(0);
	}
	waitpid(r1, NULL, 0);
    	waitpid(r2, NULL, 0);
    	waitpid(r3, NULL, 0);
    	waitpid(r4, NULL, 0);

	printf("parent: done.\n");
}

