/*
 *  Simple TCP string echo server.
 */


/*
 * ----- Header files -----
 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <resolv.h>
#include <unistd.h>


void check_endianness(void)
{
    unsigned int a = 0xAABBCCDD;
    unsigned char * c;
    
    c = (unsigned char *)&a;
    printf("0x%X - 0x%X - 0x%X - 0x%X\n", *(c + 0), *(c + 1), *(c + 2), *(c + 3));
    
    while(1);
}

/*
 * ----- Function: main() -----
 */
int main(void)
{
    int serverfd, clientfd, rcv_len;
    struct sockaddr_in self_addr, client_addr;
    unsigned int addr_len = sizeof(client_addr); 
    char buffer[1024];

    check_endianness();  
        
    // Open server socket.
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverfd < 0)
    {
        perror("Socket:");
        exit(errno);
    }
    
    // Initialize server address and port structure.
    bzero(&self_addr, sizeof(self_addr));
    self_addr.sin_family = AF_INET;
    self_addr.sin_port = htons(17231);
    self_addr.sin_addr.s_addr = INADDR_ANY;
    
    // Bind server socket.
    if(bind(serverfd, (struct sockaddr *)&self_addr, sizeof(self_addr)))
    {
    	perror("Bind");
    	exit(errno);
    }
    
    // Start listening on server socket. 
    if(listen(serverfd, 20) != 0)
    {
        perror("Listen");
        exit(0);    	
    }
    
    // Accept incoming connection from a client.
    clientfd = accept(serverfd, (struct sockaddr*)&client_addr, &addr_len);
    printf("%s:%d, connected...\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Echo received data.
    while(1)
    {
        // Receive data from client, exit if conncetion closed.
        rcv_len = recv(clientfd, buffer, 1024, 0);
        if(rcv_len <= 0)
		{
            break;
    	}

        // Insert string terminator at the end and print.
        buffer[rcv_len] = '\0';
        printf("String received from the client: \"%s\"\n", buffer);
    	
		// Echo received data.
        send(clientfd, buffer, rcv_len, 0);
    }
    
	// Close all open sockets.
    perror("Closed");
	close(clientfd);
    close(serverfd);
    exit(0);
}
