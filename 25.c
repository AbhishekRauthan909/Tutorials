/*
============================================================================
Name : 25.c
Author:Abhishek Rauthan
Description:Write a program to create three child processes. 
The parent should wait for a particular child (use waitpid system call).
Date: 7Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    int cpid[3];
    for(int i=0;i<3;i++)
    {
        cpid[i]=fork();
        if(cpid[i]==0)
        {
            printf("\nThis is child %d and my process id is %d",i+1,getpid());
            exit(i);
        }
        else if(cpid[i]==-1)
        {
            printf("\nError in creating the file");
        }
    }
    int term_pid=waitpid(cpid[2],NULL,0);
    printf("\nWe want to terminate the %d and we have successfully terminated %d",cpid[2],term_pid);
}