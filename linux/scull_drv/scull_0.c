 /*
 * A sample device driver. Requires a special makefile to build.
 */


/*
 * ----- Header files -----
 */
#include <linux/init.h>
#include <linux/module.h>


/*
 * ----- Module information -----
 */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shahzeb Ihsan");


/*
 * ----- Function:scull_init() -----
 */
static int scull_init(void)
{
    printk(KERN_ALERT "Initializing scull device driver...\n");
    return 0;
}