#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void buscar(char * dir){
		int cont=0,cont2=0;
		printf("DIRECTORIO: %s\n",dir);
		DIR* direc= opendir(dir);
		if (direc == NULL) {
		    perror("opendir");
		    exit(-1);
		}
		struct stat atributos;
		struct dirent * entrada; 
		printf("Los i-nodos son:\n");
		char new_dir[100];
		
		while((entrada=readdir(direc))!=NULL){
			char aux[200];
			
			strcpy(aux,dir);
			strcat(aux,"/");
			strcat(aux,entrada->d_name);
			if(stat(aux,&atributos)<0){
				perror("stat");
				exit(-1);
			}
			if(strcmp(entrada->d_name, ".")==0 || strcmp(entrada->d_name, "..")==0 || !S_ISDIR(atributos.st_mode))
			{
				if(S_ISREG(atributos.st_mode) && (atributos.st_mode & S_IXGRP) && (atributos.st_mode & S_IXOTH))
				{
					printf("%s %d \n",entrada->d_name,entrada->d_ino );
					cont+=atributos.st_size;
					cont2++;
				}
			}
			else
			{
				strcpy(new_dir,dir);
				strcat(new_dir,"/");
				strcat(new_dir,entrada->d_name);
				buscar(new_dir);
			}

		}
		printf("Existen %i archivos regulares con permiso x para grupo y otros\n",cont2);
		printf("El tamaño total ocupado por dichos archivos es %i bytes\n",cont);
}
int main(int argc, char * argv[]){
	char dir[100];
	if(argc==1){
		strcpy(dir,".");
	}
	else
		if(argc==2)
			strcpy(dir,argv[1]);
	else
		{
			printf("\nSintaxis de ejecucion: ./ejercicio3 ó ./ejercicio3 [<directorio>]\n\n");
			exit(-1);
		}
	buscar(dir);
}
