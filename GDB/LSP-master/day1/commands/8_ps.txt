ps command 
=====================

ps -- process status

Provides information about currently running processes, including their process identification numbers (PIDs)

When ps is used without any option, it provides information about two processes : shell and ps

panther2@ubuntu:/tmp$ ps
   PID TTY          TIME CMD
 39235 pts/11   00:00:01 bash
 47154 pts/11   00:00:00 ps

TIME is the amount of CPU (central processing unit) time in minutes and seconds that the process has been running

CMD is the name of the command that launched the process.

TTY is the name of the console or terminal. Useful on a multi user network

Common use of ps : ps aux | less

a -- list the processes of all users on the system rather than just those of the current user

u -- provide detailed information about each process. 

x -- adds to the list processes, such as daemons, which are programs that are launched during booting

An alternative set of options for viewing all the processes running on a system is

ps -ef | less

The -e option generates a list of information about every process currently running.

The -f option generates a listing that contains fewer items of information

The pstree command is similar to ps in that it can be used to show all of the processes on the system along with their PIDs

shows how processes are related to each other and in that it provides less detailed information about each process than does ps.






