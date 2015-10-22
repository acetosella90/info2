//chat servidor
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int bindeo_serv (int , int);

int main()
{
	struct sockaddr_in client ;
	int sock1 , sock2 , puerto , bindeo , list , tam;
	char envi[1024] , reci[1024];

	system("clear");
	printf("Introduzca el puerto de escucha\n");
	scanf("%d" , &puerto);

	sock1 = socket(AF_INET , SOCK_STREAM , 0);
	if(sock1 == -1)
	{
		printf("Error en la apertura del socket\n");
		exit(-1);
	}

	bindeo = bindeo_serv (sock1 , puerto);
	if(bindeo == -1)
	{
		printf("Error en el bindeo\n");
		exit(-1);
	}

	list = listen(sock1 ,5);
	if(list == -1)
	{
		printf("Error en la funcion listen();\n");
		exit(-1);
	}

	printf("SERVIDOR EN ESPERA\n");

	tam = sizeof(struct sockaddr_in);
	sock2 = accept(sock1 , (struct sockaddr *) &client , &tam);
	if(sock2 == -1)
	{
		printf("Error en la funcion accept()\n");
		exit(-1);
	}

	printf("Sesion abierta\n");
	printf("Cliente conectado\n");

	while(1)
	{
		recv(sock2 , reci , sizeof(reci) , 0);
		if(strcmp(reci,"salir") == 0)
		{
			printf("Fin de la conexion\n");
			break;
		}
		else
		printf("Cliente:%s\n",reci);

		printf("Escribir mensaje\n");
		scanf("%*c%[^\n]",envi);
		//gets(envi);
		send(sock2 , envi , sizeof(envi) , 0);
		if(strcmp(envi , "salir") == 0)
		{
			printf("Fin de la conexion\n");
			break;
		}
	}
	close(sock1);
	close(sock2);
	return 0;

}

int bindeo_serv (int sock , int puert)
{
	struct sockaddr_in server;

	//carga de datos
	server.sin_family = AF_INET;
	server.sin_port = htons (puert);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&(server.sin_zero) , 8);

	return bind(sock , (struct sockaddr *) &server , sizeof(struct sockaddr));
}