ltrace(1) also allows you to selectively trace library calls when executed with the “-e” option and a set of calls to trace:

$ ltrace -e malloc /bin/cat


