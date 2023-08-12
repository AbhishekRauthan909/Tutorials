#include<stdio.h>
#include<fcntl.h>
int main()
{
   int fd=creat("test",0666);
   printf("The files descriptor value is %d",fd);
}
