/****************
* Helloworld.c
* The most simplistic C program ever written.
* An epileptic monkey on crack could write this code.
*****************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(void)
{
	int test_sock, in_sock;	
	socklen_t len_client;
	char msg[] = "Hello, OpenWRT!!!\n";
	struct sockaddr_in tcp_server, tcp_client;

	test_sock = socket(AF_INET, SOCK_STREAM, 0);	
	if(test_sock < 0)	
	{
		printf("Socket didn't open :(\n");
	}
	else
	{
		printf("Socket opened :)\n");
	}	
	
	tcp_server.sin_family = AF_INET;
	tcp_server.sin_addr.s_addr = htonl(INADDR_ANY);	
	tcp_server.sin_port = htons(17231);

	if(bind(test_sock, (struct sockaddr *)&tcp_server, sizeof(tcp_server)) < 0)
	{
		printf("Error binding socket\n");
	}
	else
	{
		printf("Socket bound :)\n");
	}

	printf("Waiting for client to connect...\n");
	if(listen(test_sock, 0) == -1)
	{
		printf("Unable to listen :(\n");
	}

	len_client = sizeof(tcp_client);
	in_sock = accept(test_sock, (struct sockaddr *)&tcp_client, &len_client);
	if(in_sock < 0)
	{
		printf("Unable to accept connection :(\n");
	}

	send(in_sock, msg, strlen(msg), 0);

	return 0;
}

