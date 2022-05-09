#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h> 
#include <stdlib.h> 

// codico a implementar descrito por la practica
int listdir(char* d){ 
	
	DIR* dir = opendir(d);
	if (!dir){
		printf("error al intentar abrir directorio\n");
		return -1;
	}

	struct dirent* entry;
	printf("Contenidos del directorio:\n");
	while ((entry = readdir(dir)) != NULL) {//va leyendo entradas a medida que se llama
		printf("Nombre de fichero: %s\n", entry->d_name);
		//utiliza esta funcion de otro ejercicio:
		//estadof(entry->d_name);
		printf("\n\n");
	}

	if (closedir(dir) == -1){
		printf("problema al cerrar directorio\n");
		return -1;
	}

	return 0;
}

//MAIN con la declaracion de los argumentos
int main(int argc, char* argv[]){

	if (argc < 2){
		printf("No contiene un arguemnto\n");
		return -1;
	}
	listdir(argv[1]); //llamamos al listdir con 1 argumento (el nombre del fichero)
	return 0;
}


//Executing task: C/C++: gcc-8 compilar archivo activo <

//Iniciando la compilación...
// /usr/bin/gcc-8 -fdiagnostics-color=always -g /home/alumno/Documentos/Software/listdir.c -o /home/alumno/Documentos/Software/listdir

// La compilación finalizó correctamente.