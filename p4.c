#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
  int forw=open("demo.txt",O_RDWR);
  if(forw==-1)
  {
    printf("There is an error in opening file in read write mode");
    return 1;
  }
  else
  {
    printf("The file opened in read write mode");
  }
  int foxl=open("demo.txt",O_CREAT|O_EXCL,0666);
  if(foxl==-1)
  {
    printf("There is an error opening file");
    return 1;
  }
  else
  {
    printf("The file opened");
  }
  return 0;
}
  
