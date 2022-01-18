cmd_/home/nick/programming/kernel_hw/modules.order := {   echo /home/nick/programming/kernel_hw/hello.ko; :; } | awk '!x[$$0]++' - > /home/nick/programming/kernel_hw/modules.order
