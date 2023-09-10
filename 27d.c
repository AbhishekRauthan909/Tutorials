/*
============================================================================
Name : 27a.c
Author:Abhishek Rauthan
Description:Write a program to execute ls -Rl by the following system calls 
d. execv 
Date: 5Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main() {
    char *a[]={"/bin/ls","-Rl",NULL};
    execv("/bin/ls",a);
    return 0;
}