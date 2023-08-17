free
===============

The free utility displays in kilobytes

	the current (approximate) amount of memory used

	free, and

	available  on the system as whole

It further divides the used memory between shared buffer/page-cached

It also displays swap partition statistics.

$ free
             total       used       free     shared    buffers     cached
Mem:       7088788    2477848    4610940      13892     686348     746876
-/+ buffers/cache:    1044624    6044164
Swap:            0          0          0

$ free | grep "^Mem"
Mem:       7088788    2477740    4611048      13892     686428     746880

This displays only the Mem line

We see the two scenarios executing; check out the values of the free column.

We allocate, and leak, a tiny amount of memory (32 bytes) but in a loop 100,000 times: 
	Leaked memory = 297708 - 293120 = 4588 KB ~= 4.5 MB 

We allocate, and leak, a large amount of memory (1 MB) in a loop 12 times: 
	Leaked memory = 292616 - 280992 = 11624 KB ~= 11.4 MB 

Of course, do realize that once the process dies, all its memory is freed back to the system. That's why we performed the one-liner script within the process, while it was alive.


