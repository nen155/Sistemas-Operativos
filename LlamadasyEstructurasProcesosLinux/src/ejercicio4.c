#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	pid_t valorDevuelto;
	int nhijos=5;
	int nprocess=5;
	int i;
	if(setvbuf(stdout,NULL,_IONBF,0)) {
		perror("\nError en setvbuf");
	}
	for(i=0;i<nprocess;i++){
		if((valorDevuelto=fork())==0){
			printf("Soy el hijo: %i\n\n",getpid());
			exit(0);
		}
	}
	int * status;
	for (i = 0; i < nprocess; ++i){
		valorDevuelto = wait(&status);
		printf("Acaba de terminar mi hijo con %i\n\n",valorDevuelto);
		printf("Me quedan %i hijos\n\n",--nhijos);
	}
	
	exit(0);
}
