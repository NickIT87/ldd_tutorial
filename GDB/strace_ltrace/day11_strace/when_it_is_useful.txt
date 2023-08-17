When Is strace Useful?
==========================

strace is very useful while debugging crashes.  Some scenarios where strace can be helpful are –


----> When you don't have source code

----> program behaving poorly

----> nothing in the log files

----> nothing in stdout

----> no ports responding

----> don't want to open gdb

----> Debugging why an installation crashes on a machine.

----> Debugging random crashes that are most probably due to the program running out of memory or due to it requesting an arbitrarily large chunk of memory.


----> Finding out how the program interacts with the file system.

----> Debugging crashes reproducibly only on one machine.

----> Debugging crashes in unfamilar code or in cases when sources are unavailable.

. strace may provide you with valuable information for many problem cases, for
example: which config files really were read, which was the last file or shared library read before your
program crashed, and so on
                                     
