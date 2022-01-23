## create device node
sudo mknod /dev/chrdrv c 500 0
ls -la /dev/chrdrv
sudo chmod a+rw /dev/chrdrv

## load module
sudo insmod chrdev.ko

## check module load
lsmod | grep chrd
cat /proc/modules | grep chrd

## logs
sudo tail -f /var/log/syslog

## work with module
echo "!" >/dev/chrdrv