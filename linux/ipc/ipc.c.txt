/*
 * Program for testing IPC.
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
#include <sys/stat.h>
#include <sys/shm.h>


/*
 * ----- Function: main() -----
 */
int main(void)
{
    int segment_id;
    unsigned char * shared_memory;
    struct shmid_ds shmbuff;
    int segment_size;
    const int shared_segment_size = 0x6400;
    
    // Allocate a shared memory segment.
    segment_id = shmget(IPC_PRIVATE, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    
    // Attach shared memory segment.
    shared_memory = (unsigned char *)shmat(segment_id, 0, 0);
    printf("Shared memory attached at address: 0x%08X\n", (unsigned int)shared_memory);
    
    // Determine segment's size.
    shmctl(segment_id, IPC_STAT, &shmbuff);
    segment_size = shmbuff.shm_segsz;
    printf("Segment size: %d\n", segment_size);
    
    // Write a string to the shared memory.
    sprintf((char *)shared_memory, "This is a string being written to the shared memory.");
    
    // Detach the shared memory segment.
    shmdt(shared_memory);
    
    // Reattach the memory segment at a different address.
    shared_memory = (unsigned char *)shmat(segment_id, (void *)0x5000000, 0);
    printf("Shared memory reattached at address: 0x%08X\n", (unsigned int)shared_memory);
    
    // Print out the string from shared memory.
    printf("String in shared memory: \"%s\n\"", (char *)shared_memory);
    
    // Detach the shared memory segment.
    shmdt(shared_memory);
    
    // Deallocate the shared memory segment.
    shmctl(segment_id, IPC_RMID, 0);
    
    exit(0);
}
