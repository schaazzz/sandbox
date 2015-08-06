/*
 * A simple program to test the ioctl function call by using
 * it to eject the CD-ROM.
 */


/*
 * ----- Header files -----
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/cdrom.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


/*
 * ----- Function: main() -----
 */
int main(void)
{
    int fd, retcode;
    
    // Open a file descriptor to the CD-ROM.
    fd = open("/dev/scd0", O_RDONLY);
    
    // Eject the CD-ROM.
    printf("Ejecting the CD-ROM...\n");
    retcode = ioctl(fd, CDROMEJECT);
    
    if(retcode < 0)
    {
        printf("Failed to eject the CD-ROM...\n");
    }
    else
    {
        printf("CD-ROM ejected...\n");
    }
    
    // Close the file descriptor.
    close(fd);
    
    exit(0);
}
