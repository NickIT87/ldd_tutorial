Printk is implemented by using a ring buffer in the kernel with a size of __LOG_BUF_LEN bytes where __LOG_BUF_LEN equals (1 << CONFIG_LOG_BUF_SHIFT).

See kernel/printk/printk.c file

$ cat /boot/config-`uname -r` | grep CONFIG_LOG_BUF_SHIFT

CONFIG_LOG_BUF_SHIFT can be changed from menuconfig

make menuconfig -> General Setup -> Kernel log buffer size

Note: dmesg reads by default a buffer of max 16392 bytes, so if you use a larger logbuffer you have to invoke dmesg with the -s parameter e.g.:


### CONFIG_LOG_BUF_SHIFT 18 = 256k
$ dmesg -s 256000

To increase the buffer size we can also use kernel command line:

log_buf_len=4M

Sets the kernel buffer length to 4Megabytes


