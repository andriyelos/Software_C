// Implementar una funcion que copie de un fichero a
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>


//Esta funcion utiliza llamadas al sistema operativo
int copiaFichero(char* source, char* target){
	
	int fd_or, fd_des;              // declarar enteros de origen y destino 
	char bloque[512];   

	if ((fd_or = open(source, O_RDONLY)) < 0) {         //lo habrimos en solo lectura
		perror("Fallo en la apertura \n");
		return -1;
	}

	if ((fd_des = creat(target, 0777)) < 0)               //creamnos con su permiso 0777
	{
		perror("Fallo en  la creacion del fichero\n");
		return -1;
	}
	
	int bytesRead, bytesWritten; // se declara los bytes leidos y escritos
	while ((bytesRead = read(fd_or, bloque, 512)) > 0){
		bytesWritten = write(fd_des, bloque, bytesRead); //escribimos en el destino los bytes leidos
		if (bytesWritten < 0){
			perror("error en write\n");
			return -1;
		}
	}
	if(bytesRead == -1){            //si devuelve -1 algo a fallado
		perror("error en read\n");
		return -1;
	}

	if ((close(fd_or) == -1) || (close(fd_des) == -1)) {    // para cerrarlo comprobamos 
		perror("error al cerrar el ficheros");  
		return -1;
	}

	return 0;
}

int Copia_Fichero_C(char* source, char* target){
	
	char buffer[512];
	FILE* fd_source, *fd_des; //

	fd_source = fopen(source, "rb"); //abrir en  modo lectura de bytes 
	if (fd_source == NULL){
		printf("problema al abrir %s\n", source); 
		return -1;
	}

	fd_des = fopen(target, "wb"); //abrir en modo escritura de archivos de bytes
	if (fd_des == NULL){
		printf("problema al abrir %s\n", target);
		return -1;
	}

	int bytesRead, bytesWritten;    //declaracion de bytes de lectura y escritura
	
	while((bytesRead = fread(buffer,1,512,fd_source)) > 0 ){	
		bytesWritten = fwrite(buffer, 1, bytesRead, fd_des);
		if (bytesWritten < bytesRead) {
			printf("Error en write\n");
			return -1;
		}
	}

	fclose(fd_source); fclose(fd_des);
	return 0;

}

int main(int argc, char* argv[]){
	if (argc < 3) {
		printf("Uso del programa: %s <origen> <destino>\n", argv[0]);
		return 1;
	}
	return copiaFichero(argv[1], argv[2]);
	
}


//Executing task: C/C++: gcc-8 compilar archivo activo <

//Iniciando la compilación...
///usr/bin/gcc-8 -fdiagnostics-color=always -g /home/alumno/Documentos/Software/Copiar_Fichero.c -o /home/alumno/Documentos/Software/Copiar_Fichero

//La compilación finalizó correctamente.