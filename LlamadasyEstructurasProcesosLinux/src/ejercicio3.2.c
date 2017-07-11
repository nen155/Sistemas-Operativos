#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	pid_t childpid;
	int nprocs=10;
	int i;
		/*
	Jerarquía de procesos tipo 2
	*/
	printf("\nJERAQUIA 2\n");
	if(setvbuf(stdout,NULL,_IONBF,0)) {
			perror("\nError en setvbuf");
	}

	for (i=1; i < nprocs; i++) {
		if ((childpid= fork()) == -1) {
			fprintf(stderr, "Could not create child %d: %s\n",i,strerror(errno));
			exit(-1);
		}
		if (!childpid){
			printf("Proceso hijo: %i\n",getppid());
			break;
		}else
			printf("Proceso padre: %i\n",getpid());
		
	}

	
}



