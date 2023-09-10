/*
============================================================================
Name : 22.c
Author:Abhishek Rauthan
Description:Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. 
Check output of the file.
Date: 7Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int argc,char*argv[])
{
    int fd=open(argv[1],O_CREAT|O_RDWR,0744);
    if(argc!=2)
    {
        printf("\nError in open the file\n");
    }
    if(fd==-1)
    {
        printf("\nFile not opened");
        exit(2);
    }
    int cpid=fork();
    if(cpid==-1)
    {
        printf("\nError in creating the file");
        exit(3);
    }
    else if(cpid==0)
    {
        int x=10;
        int y;
        write(fd,&x,sizeof(x));
        lseek(fd,-(sizeof(y)),SEEK_CUR);
        read(fd,&y,sizeof(y));
        printf("\n%d",y);
        close(fd);
    }
    else
    {
        int x=20;
        int  z;
        write(fd,&x,sizeof(x));
        lseek(fd,-(sizeof(x)),SEEK_CUR);
        read(fd,&z,sizeof(z));
        printf("%d",z);
        close(fd);
    }
}