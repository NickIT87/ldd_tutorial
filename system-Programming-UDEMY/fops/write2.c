/* Program to create a new file and write data to new file */

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

  strcpy(buf,"Sample file write");

  int fd = open("new_out.txt", O_WRONLY  | O_CREAT, 0774); 
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


