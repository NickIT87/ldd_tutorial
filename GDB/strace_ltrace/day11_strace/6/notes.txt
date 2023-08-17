Child Processes
==================

Sometimes the process you trace doesn't do the real work itself, but delegates it to child processes that it creates.

If that's the case, you may want to pass -f to make strace "follow forks" and trace child processes, too, as soon as they're made.


'-ff' - follows forks with separate output files per-fork
