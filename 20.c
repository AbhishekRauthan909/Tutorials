/*
Name-20.c
Author-Abhishek Rauthan
Description-Find out the priority of your running program. Modify the priority with nice command.
Date-1 sep 2023
*/
#include<sys/time.h>
#include<stdio.h>
#include<sys/resource.h>
int main()
{
    int which;
    id_t who;
    which=PRIO_PROCESS;
    who=0;
    int errno=0;
    int prio=getpriority(which,who);
    if(prio==-1&&errno!=0)
    {
        printf("error");
    }
    else
    {
        printf("\nNice value =%d\n",prio);
    }
}
