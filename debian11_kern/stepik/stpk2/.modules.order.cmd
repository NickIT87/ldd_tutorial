cmd_/home/nick/ldd_tutorial/debian11_kern/stepik/stpk2/modules.order := {   echo /home/nick/ldd_tutorial/debian11_kern/stepik/stpk2/chrdev.ko; :; } | awk '!x[$$0]++' - > /home/nick/ldd_tutorial/debian11_kern/stepik/stpk2/modules.order