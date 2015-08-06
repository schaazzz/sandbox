/*
 *  Simple TCP string echo client.
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
#include <curses.h>
#include <unistd.h>


/*
 * ----- Constants definitions -----
 */
#define KEY_ENT      10
#define KEY_ESC      27
#define FLAG_EXIT   -1


/*
 * ----- Function: main() -----
 */
int main(void)
{
    int serverfd, flag, n = 0, rcv_len;
    struct sockaddr_in server_addr;
    char buffer[1024], temp;

    // Initialize "ncurses".
    initscr();
    cbreak();
    noecho();

    // Open socket for connecting to the server.
    if((serverfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket");
        exit(errno);
    }

    // Initialize server address and port structure.
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(17231);

    if(inet_aton("127.0.0.1", &(server_addr.sin_addr)) == 0)
    {
        perror("127.0.0.1");
        exit(errno);
    }

    // Connect to the server.
    if (connect(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0 )
	{
        perror("Connect");
        while(1);
        exit(errno);
	}

    printw("Connected to %s:%d...\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

    // Send data to the server.
    while(1)
    {
        n = 0;
        flag = 0;
        printw("Enter string to send to the server for echoing (ESC to exit):\n");
        
        // Input loop.
        while(1)
        {
            temp = getch();
            
            // Was the ESC key pressed?
            if(temp == KEY_ESC)
            {
                flag = FLAG_EXIT;
                break;
            }
            // Was the ENTER key pressed?
            else if(temp == KEY_ENT)
            {
                break;
            }
            else
            {
                buffer[n++] = temp;
                printw("%c", temp);
            }
        }
        
        // Was the ESC key pressed?
        if(flag == FLAG_EXIT)
        {
            break;
        }
        
        // Send string to the echo server.
        send(serverfd, buffer, n, 0);
        
        // Receive echo string from the server.
        rcv_len = recv(serverfd, buffer, 1024, 0);
        
        // Insert string terminator at the end and print.
        buffer[rcv_len] = '\0';
        printw("\nString echoed by the server: \"%s\"\n", buffer);
    }

    // Close socket and "ncurses" window.
    close(serverfd);
    endwin();
    exit(0);
}
