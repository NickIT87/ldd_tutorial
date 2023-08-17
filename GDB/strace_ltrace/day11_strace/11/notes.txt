strace -s 2000 -f ./program1

the “-s” flag to strace telling it the maximum string size we want it to print. This is helpful for showing expanded function arguments. 

Here we pass 2000, which is abitrarily “enough” to see everything we need to see in this program. The default is 32, which in my experience means we’ll almost definitely miss information we care about in the trace

