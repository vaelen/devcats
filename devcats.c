/******
This file is part of devcats.

Copyright 2017, Andrew Young <andrew@vaelen.org>

    Devcats is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

    Devcats is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
along with devcats.  If not, see <http://www.gnu.org/licenses/>.
******/

#include "cats.h"

#include <linux/init.h>           // Macros used to mark up functions e.g. __init __exit
#include <linux/module.h>         // Core header for loading LKMs into the kernel
#include <linux/device.h>         // Header to support the kernel Driver Model
#include <linux/kernel.h>         // Contains types, macros, functions for the kernel
#include <linux/fs.h>             // Header for the Linux file system support
#include <asm/uaccess.h>          // Required for the copy to user function
#include <linux/mutex.h>          // Required for the mutex functionality
#include <linux/string.h>

#define  DEVICE_NAME "cats"
#define  CLASS_NAME  "cats"

static DEFINE_MUTEX(cats_mutex);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andrew Young");
MODULE_DESCRIPTION("The /dev/cats driver.");
MODULE_VERSION("0.1");

static int majorNumber = 0;
static struct class*  catsClass  = NULL;
static struct device* catsDevice = NULL;
static int numberOpens = 0;

static int cats_pos = 0;

static ssize_t device_read(struct file *file_ptr, char *buffer, size_t buffer_size, loff_t *position) {
    int bytes_read = 0;
    char *c = cats;
    int cats_size = strlen(c);

    /*
     * Actually put the data into the buffer
     */
    while (bytes_read < buffer_size) {
        cats_pos++;
        if (cats_pos >= cats_size) {
            cats_pos = 0;
            c = cats;
        }
        //put_user(cats[cats_pos], buffer++);
        put_user(*(c++), buffer++);
        bytes_read++;
    }

    /*
     * Most read functions return the number of bytes put into the buffer
     */
    *position += bytes_read;
    return bytes_read;
}

static int device_open(struct inode *inodep, struct file *filep){
    if(!mutex_trylock(&cats_mutex)){
        printk(KERN_ALERT "/dev/cats: Device in use by another process");
        return -EBUSY;
    }
    numberOpens++;
    printk(KERN_INFO "/dev/cats: Device has been opened %d time(s)\n", numberOpens);
    return 0;
}

static int device_release(struct inode *inodep, struct file *filep){
    mutex_unlock(&cats_mutex);
    printk(KERN_INFO "/dev/cats: Device successfully closed\n");
    return 0;
}

static struct file_operations devcats_fops = {
        .owner   = THIS_MODULE,
        .open    = device_open,
        .release = device_release,
        .read    = device_read,
};

static int __init devcats_init(void){
    int result = 0;
    printk(KERN_INFO "/dev/cats: Starting.\n");
    result = register_chrdev( 0, DEVICE_NAME, &devcats_fops );
    if( result < 0 )
    {
        printk(KERN_WARNING "/dev/cats: can't register character device with errorcode = %i", result );
        return result;
    }
    majorNumber = result;
    printk(KERN_NOTICE "/dev/cats: registered character device with major number = %i and minor numbers 0...255", majorNumber );

    // Register the device class
    catsClass = class_create(THIS_MODULE, CLASS_NAME);
    if (IS_ERR(catsClass)){                // Check for error and clean up if there is
        unregister_chrdev(majorNumber, DEVICE_NAME);
        printk(KERN_ALERT "/dev/cats: Failed to register device class\n");
        return PTR_ERR(catsClass);          // Correct way to return an error on a pointer
    }
    printk(KERN_INFO "/dev/cats: device class registered correctly\n");


    // Register the device driver
    catsDevice = device_create(catsClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);
    if (IS_ERR(catsDevice)){               // Clean up if there is an error
        class_destroy(catsClass);           // Repeated code but the alternative is goto statements
        unregister_chrdev(majorNumber, DEVICE_NAME);
        printk(KERN_ALERT "/dev/cats: Failed to create the device\n");
        return PTR_ERR(catsDevice);
    }

    mutex_init(&cats_mutex);

    printk(KERN_INFO "/dev/cats: Started.\n");
    return 0;
}

static void __exit devcats_exit(void){
    printk(KERN_INFO "/dev/cats: Stopping.\n");
    if(majorNumber != 0)
    {
        device_destroy(catsClass, MKDEV(majorNumber, 0));     // remove the device
        class_unregister(catsClass);                          // unregister the device class
        class_destroy(catsClass);                             // remove the device class
        unregister_chrdev(majorNumber, DEVICE_NAME);
        mutex_destroy(&cats_mutex);
    }
    printk(KERN_INFO "/dev/cats: Stopped.\n");
}

module_init(devcats_init);
module_exit(devcats_exit);
