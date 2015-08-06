/*
 * A sample kernel module. Requires a special makefile to build.
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
 * ----- Function: mod_init() -----
 */
static int mod_init(void)
{
    printk(KERN_ALERT "My first kernel module starting :)\n");
    return 0;
}


/*
 * ----- Function: mod_exit() -----
 */
static void mod_exit(void)
{
    printk(KERN_ALERT "My first kernel module exiting :(\n");
}


/*
 * ----- Register module initialization and exit functions -----
 */
module_init(mod_init);
module_exit(mod_exit);
