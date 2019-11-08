#include <wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    
	int r1 = fork();
	
	if (r1 == 0) {
		execlp("PYTHON", "PYTHON_3", "add.py", argv[1], argv[2], NULL);
		exit(0);
	}    
	int r2 = fork();
	
	if (r2 == 0) {
		execlp("JAVA", "JAVA", "divide", argv[1], argv[2], NULL);
		exit(0);
	} 
	int r3 = fork();

	if (r3 == 0) {
		execlp("NODEJS", "NODEJS", "minus.js", argv[1], argv[2], NULL);
		exit(0);
	}    

	int r4 = fork();
	
	if (r4 == 0) {
		execlp("BASH", "BASH", "multiply.sh", argv[1], argv[2], NULL);
		exit(0);
	} 
    	waitpid(r1, NULL, 0);
    	waitpid(r2, NULL, 0);
    	waitpid(r3, NULL, 0);
    	waitpid(r4, NULL, 0);
	printf("PARENT: done.\n");
	



}

