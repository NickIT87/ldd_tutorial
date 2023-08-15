/* Program to write to a existing file in O_APPEND mode and  O_TRUNC mode*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
#include <fcntl.h> 
//#include <malloc.h>
#include <unistd.h>


int main() 
{ 
  int sz; 
  char buf[100];

  strcpy(buf,"This is example of O_TRUNC: Sample file write2 using append flag\n");

  /* O_TRUNC => write to file from beginning , discarding old contents*/
  /* O_APPEND => write the contents of file from the end of existing file contents*/
  int fd = open("output.txt", O_WRONLY  | O_TRUNC  ); 
  if (fd < 0) 
  { 
     perror("Error occured during open"); 
     exit(1); 
  } 
  printf("length of buf is (%d)",(int)strlen(buf));
  sz = write(fd, buf, strlen(buf)); 
  
  printf("\nwrite() returned  %d\n", sz); 
  
  close(fd); 
} 


