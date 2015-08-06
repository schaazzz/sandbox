/*
 * Program to test various aspects of multi-threading programming.
 */

 
/*
 * ----- Header files -----
 */
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
//#include <sys/wait.h>
#include <pthread.h>


/*
 * ----- Local scope variables -----
 */
static pthread_key_t thread_log_key;


/*
 * ----- Function prototypes -----
 */
void * thread_function(void * thread_arg);
void write_to_thread_log(const char * msg);
void close_thread_log(void * thread_log);


/*
 * ----- Function: main() -----
 */
int main(void)
{
    int i;
    pthread_t threads[5];
    
    // Remove all previously created log files.
    system("rm *.log");
    
    // Create a key to associate thread log file pointers in thread specific data. Use close_thread_log()
    // to clean up the file pointers.
    pthread_key_create(&thread_log_key, close_thread_log);
    
    // Create threads.
    for(i = 0; i < 5; i++)
    {
        pthread_create(&(threads[i]), NULL, thread_function, NULL);
    }
    
    // Wait for all threads to join.
    for(i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }

    exit(0);
}


/*
 * ----- Function: write_to_thread_log() -----
 */
void write_to_thread_log(const char * msg)
{
    FILE * thread_log = (FILE *)pthread_getspecific(thread_log_key);
    fprintf(thread_log, "%s\n", msg);
}


/*
 * ----- Function: close_thread_log() -----
 */
void close_thread_log(void * thread_log)
{
    fprintf((FILE *)thread_log, "Thread exiting...\n");
    fclose((FILE *)thread_log);
}


/*
 * ----- Function: thread_function() -----
 */
void * thread_function(void * thread_arg)
{
    char thread_log_filename[30];
    FILE * thread_log;
    
    // Generate thread filename.
    snprintf(thread_log_filename, 30, "thread%02d.log", (int)pthread_self());
    
    // Open the log file.
    thread_log = fopen(thread_log_filename, "w");
    
    // Store the file pointer in thread-specific data under thread_log_key.
    pthread_setspecific(thread_log_key, thread_log);
    
    // Write message to thread log.
    write_to_thread_log("Thread starting...");

    return NULL;
}
