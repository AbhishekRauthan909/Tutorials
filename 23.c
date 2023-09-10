/*
============================================================================
Name : 23.c
Author:Abhishek Rauthan
Description:Write a program to create a Zombie state of the running program.
Date: 7Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
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
        printf("\nThis is child process and my pid is %d",getpid());
        printf("\nI am child and exiting");
        exit(0);
    }
    else
    {
        sleep(60);
        int tepid=wait(NULL);
        printf("\nzombie process %d",tepid);
        printf("\nNow parent awake");
    }
    return 0;
}