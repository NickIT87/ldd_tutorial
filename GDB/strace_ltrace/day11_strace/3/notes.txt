-t Print the time of day at the start of each line.
-tt to the microsecond

$ strace -t pwd

$ strace -tt pwd

$ strace -ttt pwd

By adding the option -t once, twice or three times, one may select different time stamp formats: 
	HH:MM:SS, 
	HH:MM:SS.microseconds, or 
	the “UNIX time” in seconds and microseconds since 1970 GMT/UTC respectively.
