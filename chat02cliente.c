//chat cliente
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
	struct sockaddr_in server ;
	int sock1 , puerto , conec;
	char envi[1024] , reci[1024] ;

	system("clear");

	printf("Ingrese puerto de conexion\n");
	scanf("%d" , &puerto);

	sock1 = socket(AF_INET , SOCK_STREAM , 0);
	if(sock1 == -1)
	{
		printf("Error al abrir el socket\n");
		exit(-1);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(puerto);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&(server.sin_zero) , 8);

	conec = connect(sock1 , (struct sockaddr *) &server ,sizeof(struct sockaddr));
	if(conec == -1)
	{
		printf("Error en la conexion\n");
		exit(-1);
	}

	while(1)
	{
		printf("Escribir mensaje\n");
		scanf("%*c%[^\n]",envi);
		// gets(envi);
		send(sock1,envi,sizeof(envi),0);
		if(strcmp(envi,"salir") == 0)
		{
			printf("Fin de la conexion\n");
			break;
		}

		recv(sock1,reci,sizeof(reci),0);
		if(strcmp(reci , "salir") == 0)
		{
			printf("Fin de la conexion\n");
			break;
		}
		printf("Servidor: %s\n",reci);
	}
	close(sock1);
}