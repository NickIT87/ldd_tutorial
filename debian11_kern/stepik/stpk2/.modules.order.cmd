cmd_/home/nick/programming/stpk2/modules.order := {   echo /home/nick/programming/stpk2/chrdev.ko; :; } | awk '!x[$$0]++' - > /home/nick/programming/stpk2/modules.order
