cmd_/home/nick/ldd_tutorial/debian11_kern/stepik/stpk2/Module.symvers := sed 's/ko$$/o/' /home/nick/ldd_tutorial/debian11_kern/stepik/stpk2/modules.order | scripts/mod/modpost -m    -o /home/nick/ldd_tutorial/debian11_kern/stepik/stpk2/Module.symvers -e -i Module.symvers   -T -