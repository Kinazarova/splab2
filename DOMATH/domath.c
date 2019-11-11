#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if (argc<3) {
		printf("TOO FEW ARGS.\n");
		exit(1);
	}
	pid_t d = fork();
	if(d == 0){
		int q = atoi(argv[2]);
		int z = atoi(argv[1]);
		printf("CHAILD_4: %d / %d = %d\n",z,q,z/q);
		exit(0);
	}
	
	pid_t a = fork();

	if(a == 0){
		int q = atoi(argv[2]);
		int z = atoi(argv[1]);
		printf("CHAIL_1: %d + %d = %d\n",z,q,z+q);
		exit(0);
	}
	pid_t c = fork();
	if(c == 0){
		int q = atoi(argv[2]);
		int z = atoi(argv[1]);
		printf("CHAILD_3: %d * %d = %d\n",z,q,z*q);
		exit(0);
	}
	pid_t b = fork();
	if(b == 0){
		int q = atoi(argv[2]);
		int z = atoi(argv[1]);
		printf("CHAILD_2: %d - %d = %d\n",z,q,z-q);
		exit(0);
	}

	waitpid(a, NULL, 0);
    	waitpid(b, NULL, 0);
    	waitpid(c, NULL, 0);
    	waitpid(d, NULL, 0);

	printf("PARENT_: done.\n");
}

