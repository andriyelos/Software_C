//Implementa	 un	 programa	 que	 imprima	 el	 contenido	 de	 un	 fichero por pantalla
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){ 

	//1. Declara un descriptor de fichero denominado fd_og ( fichero de origen)
	int fd_og; //origen
	char bloque[512];

	if (argc < 2) { // un fichero de entrada 
		printf("Uso del programa: %s <fichero>\n", argv[0]);
		exit(1);
	}
	//2. Abre fichero en modo lectura utilizando open()
	if ((fd_og = open(argv[1], O_RDONLY)) < 0) { // Abrimos el fichero en modo lectura solo
		perror("Fallo en la apertura\n");
		exit(-1);
	}
	
	int bytesRead;
	//3. Lee el fichero en bloques. Si el fichero es de texto, hay que convertir cada bloque leido
	
	while ((bytesRead = read(fd_og, bloque, 511)) > 0){ 
		//4. Convierte el array bloque en cadena
		bloque[bytesRead] = '\0';   // añadimos 0 al final de nuestra cadena 
		
		printf("%s",bloque);
	}
	//5. Comprueba si hubo error en la llamada al sistema read()
	if(bytesRead == -1){
		perror("error en read\n");
		exit(-1);
	}
	//6. Cierra el fichero con close() 
	if (close(fd_og == -1)){	//comprobamos que no devuelva valor -1 
		perror("error cerrando fichero"); 	
		exit(-1);
	}

	exit(0);
}





