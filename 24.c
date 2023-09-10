/*
============================================================================
Name : 24.c
Author:Abhishek Rauthan
Description:Write a program to create an orphan process
Date: 7Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    int cpid=fork();
    if(cpid==-1)
    {
        printf("\nCan't create the child process");
        exit(1);
    }   
    else if(cpid==0)
    {
        printf("\nI am chid and now my parent process id is %d",getppid());
        sleep(8);
        printf("\nI am child and now my parent process id is %d",getppid());
    }
    else
    {
        printf("\nI am parent and my id is %d",getpid());
        sleep(4);
    }
}