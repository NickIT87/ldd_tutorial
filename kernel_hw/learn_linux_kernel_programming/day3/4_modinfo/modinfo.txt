Understanding modinfo output
==============================

vermagic: When loading a module, the strings in the vermagic value are checked if they match. If they don't match you will get an error and the kernel refuses to load the module. 

intree: All kernel modules start their developments as out-of-tree. Once a module gets accepted to be included, it becomes an in-tree module.

srcversion: is an MD4 hash of the source code used to compile the kernel module. It is calculated automatically at build time from  modpost script

retpoline: "Retpoline" was introduced to be a solution to mitigate the risk of Spectre
