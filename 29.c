/*
============================================================================
Name : 29.c
Author:Abhishek Rauthan
Description:
29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR)
Date: 5Sep, 2023.
============================================================================
*/
#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<unistd.h>
int main()
{
    int pid=getpid();
     struct sched_param para;
    int csp=sched_getscheduler(pid);
    //csp->current scheduling policy
    if(csp==-1)
    {
        printf("\nSome error occured");
        exit(1);
    }
    switch(csp)
    {
        case SCHED_FIFO:
            printf("\nSCHED_FIFO");
            break;
        case SCHED_RR:
            printf("\nSCHED_RR");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Some other scheduling process");
            break;
    }
    para.sched_priority=99;
    int choice;
    printf("\nEnter the scheduling you want to done:\n");
    printf("\n1->SCHED_FIFO");
    printf("\n2->SCHED_RR");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            if (sched_setscheduler(pid, SCHED_FIFO, &para) == -1)
             {
               printf("\nError");
               exit(2);
             }
            printf("\nScheduling policy modified successfully");
            break;
        case 2:
            if(sched_setscheduler(pid, SCHED_FIFO, &para) == -1) 
            {
               printf("\nError");
               exit(2);
            }
            printf("\nScheduling policy modified successfully");
            break;
        default:
            printf("\nWrong choice");
            break;
    }
     csp=sched_getscheduler(pid);
    //csp->current scheduling policy
    if(csp==-1)
    {
        printf("\nSome error occured");
        exit(1);
    }
    printf("\nNew priority %d",para.sched_priority);
    switch(csp)
    {
        case SCHED_FIFO:
            printf("\nSCHED_FIFO");
            break;
        case SCHED_RR:
            printf("\nSCHED_RR");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Some other scheduling process");
            break;
    }
}
