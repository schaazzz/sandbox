/*
 * A simple program to test process related functions like fork(), exec() etc.
 */
 

/*
 * ----- Header files -----
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


/*
 * ----- Function: main() -----
 */
int main(void)
{
    pid_t child_pid;
    int child_status;
    char * arg_list[] = {"ls", "-l", NULL};
    
    printf("\n*** Main process started ***\n\n");
    
    // Make a child process.
    child_pid = fork(); 
    
    if(child_pid > 0)
    {
        // Print the process ID and parent process ID for the main process.
        printf("Process ID (main process): %d\n", getpid());
        printf("Parent Process ID (main process): %d\n", getppid());
        
        // Wait for the child process to finish.
        wait(&child_status);

        // Print child process' exit information.
        if(WIFEXITED(child_status))
        {
            printf("The child process exited normally, with exit code: %d", WEXITSTATUS(child_status));
        }
        else
        {
            printf("The child process exit abnormally");
        }
    }
    else
    {
        // Increase the niceness value for the child process so that the
        // main function executes before the child process.
        nice(1);
        
        // Print the process ID and parent process ID for the child process. 
        printf("Process ID (child process): %d\n", getpid());
        printf("Parent Process ID (child process): %d\n", getppid());
        execvp("ls", arg_list);
    }
    
    printf("\n\n*** Main process finished ***\n\n");
    
    exit(0);
}
