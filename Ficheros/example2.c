//Ejercicio para leer los datos del fichero y mostrarlo por pantalla
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

struct Estructura{
	int a;
	float b;
	char c;
};

int main(int argc, char *argv[]){
	//0.- Procesar argumentos
	if (argc < 2) {
		printf("Uso %s <fichero>\n", argv[0]);
		return -1;
	}
	
	//1. Abre ahora el fichero otra vez para lectura, esta vez con open()

	int fd;
	if ((fd = open(argv[1], O_RDONLY)) < 0) {	// abrimos en solo lectura el fichero 
		perror("ha fallado la creacion del fichero\n");
		exit(1);
	}
	  
	//Lee entero en la variable y :
	int y;
	if(read(fd,&y,sizeof(int)) != sizeof(int)){	 // sizeof del valor de entero 
		perror("error leyendo el entero");
		exit(1);
	}	
	printf("Valor entero: %d\n",y);
	
	//Lee el valor de 4 enteros en la variable enteros. Imprimelo por pantalla  
	int enteros[4];
	if(read(fd,enteros,sizeof(int)*4) != (sizeof(int)*4)){		// obtenemos el mismo tamaño que en el array del apartado anterior
		perror("error al leer el arrays de enteros");
		exit(1);
	}
	int i;
	// Mostramos por pantalla los valores de cada parametro ( i ) y del array ( i) 
	for(i=0;i < 4; i++)
		printf("Valor del i %d del array: %x\n",i,enteros[i]); // recore el array y muestra cada posicion del array enteros[i]

	// Lee el valor de una estructura de tipo Estructura en la variable s.   
	struct Estructura s;
	if(read(fd,&s,sizeof(struct Estructura)) != sizeof(struct Estructura)){		// alacena el valor de la etructura y comprubea el tamaño 
		perror("error al leer la estructura");
		exit(1);
	}	
	printf("s.a de entero: %d,s.b de float: %f,s.c de char: %c\n",s.a,s.b,s.c);	// mostramos por pantalla los valores de la estructura leidos  ( %d , %f , %c) = ( int , floar , char )
	// valores s.a s.b s.c declarados anteriormente en la estructura 
		
	//Cierra el fichero con close()
	if (close(fd) == -1){		//comprobamos que no devuelva valor -1 
		perror("error cerrando el fichero");
		exit(1);
	}
		
	return 0;
}

//Executing task: C/C++: gcc-8 compilar archivo activo <

//Iniciando la compilación...
// /usr/bin/gcc-8 -fdiagnostics-color=always -g /home/alumno/Documentos/Software/LeerDatos.c -o /home/alumno/Documentos/Software/LeerDatos

//La compilación finalizó correctamente.