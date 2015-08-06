/*
 *  Simple program for testing signals.
 */


/*
 * ----- Header files -----
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <resolv.h>
#include <unistd.h>
#include <string.h>


/*
 * ----- Function prototypes -----
 */
void user_handler(int sig_num);
void int_handler(int sig_num);
void stop_handler(int sig_num);


/*
 * ----- Local scope variables -----
 */
static volatile sig_atomic_t sig_count = 0;
static volatile sig_atomic_t sig_flag = 0;


/*
 * ----- Function: main() -----
 */
int main(void)
{
    struct sigaction sig_action;
    
    // Installing a signal handler using the new POSIX interface...
    //
    // Initialize sig_action to zero.
    memset(&sig_action, 0, sizeof(struct sigaction));
    
    // Initialize signal disposition.
    sig_action.sa_handler = user_handler;
    
    // Install the signal handler for the SIGUSR1 signal.
    sigaction(SIGUSR1, &sig_action, NULL);
    
    // Installing signal handlers using the older POSIX interface...
    //
    // Install the signal handler for the SIGINT signal.
    signal(SIGINT, &int_handler);
    
    // Install the signal handler for the SIGTSTP signal.
    signal(SIGTSTP, &stop_handler);
    
    while(1)
    {
        if(sig_flag == 1)
        {
            // Reset sig_flag.
            sig_flag = 0;

            // Raise the SIGUSR1 signal.
            raise(SIGUSR1);
        }
        
        printf("SIGUSR1 was raised %d times...\r\b", sig_count);
    }
    
    exit(0);
}


/*
 * ----- Function: user_handler() -----
 */
void user_handler(int sig_num)
{
    sig_count++;
}


/*
 * ----- Function: int_handler() -----
 */
void int_handler(int sig_num)
{
    printf("\nExiting...\n");
    exit(1);
}


/*
 * ----- Function: stop_handler() -----
 */
void stop_handler(int sig_num)
{
    sig_flag = 1;
}
