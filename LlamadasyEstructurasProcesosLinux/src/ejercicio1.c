#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants        
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc==2){
		pid_t pid;
		int numero;
		numero = strtol(argv[1],NULL,10);
		if( (pid=fork())<0) {
			perror("\nError en el fork");
			exit(-1);
		}
		else if(pid==0) {  //proceso hijo ejecutando el programa
			if(numero%2==0)
			{
				char buf[]="El numero es PAR\n\n";
				if(write(STDOUT_FILENO,buf,sizeof(buf)+1) != sizeof(buf)+1) {
					perror("\nError en write");
					exit(-1);
				}
				exit(0);			
			}
			else
			{
				char buf[]="El numero es IMPAR\n\n";
				if(write(STDOUT_FILENO,buf,sizeof(buf)+1) != sizeof(buf)+1) {
					perror("\nError en write");
					exit(-1);
				}
				exit(0);
			}
		} else  //proceso padre ejecutando el programa
		{
			if(numero%4==0){
				char buf[]="El numero es divisible por 4\n\n";
				if(write(STDOUT_FILENO,buf,sizeof(buf)+1) != sizeof(buf)+1) {
					perror("\nError en write");
					exit(-1);
				}
			}
			else{
				char buf[]="El numero NO es divisible por 4\n\n";
				if(write(STDOUT_FILENO,buf,sizeof(buf)+1) != sizeof(buf)+1) {
					perror("\nError en write");
					exit(-1);
				}


			}
				
		}	
	}
	else{
		printf("\nSintaxis de ejecucion: ./ejercicio1 [<numero>]\n\n");
		exit(-1);
	}
	
}
