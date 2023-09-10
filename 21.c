/*
============================================================================
Name : 21.c
Author:Abhishek Rauthan
Description:Write a program, call fork and print the parent and child process id.
Date: 7Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    int pid=fork();
    if(pid==-1)
    {
        printf("\nError in creating the child process");
    }
    else if(pid==0)
    {
        printf("this is child and my id is %d",getpid());
        printf("\nThis is child and my parent is %d",getppid());
    }
    else
    {
        ssize_t childpid;
        while((childpid=wait(NULL))!=-1);
        printf("\nMy child process id is %d",pid);
        printf("\nThis is parent and my id is %d",getpid());
    }
}