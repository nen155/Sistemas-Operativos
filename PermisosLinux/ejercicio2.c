#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char * argv[]){

	if(argc!=3){
		printf("\nSintaxis de ejecucion: ./ejercicio2 [<nombre_directorio>] [<permisos_octal>]\n\n");
		exit(-1);

	}else
	{
		struct stat atributos;
		char * directorio = argv[1];
		int permisos = strtol(argv[2],NULL,8);
		DIR* direc= opendir(directorio);
		if (direc == NULL) {
		    perror("opendir");
		    exit(-1);
		}
		struct dirent * entrada; 
		char * nameArchiCompleto[100];
		while((entrada=readdir(direc))!=NULL){
			strcpy(nameArchiCompleto, directorio);	
			char * nombre = entrada->d_name;	
			strcat(nameArchiCompleto,"/");	
			strcat(nameArchiCompleto,nombre);
			if(stat(nameArchiCompleto,&atributos)<0)
			{
				perror("stat");
				exit(-1);
			}
			
			printf("%s : %o %o ",nombre, atributos.st_mode, permisos);
			printf("\n");
			if(chmod(nameArchiCompleto,permisos)<0)
			{
				perror("chmod");
				exit(-1);
			}		
		}
		
	}
	
}
