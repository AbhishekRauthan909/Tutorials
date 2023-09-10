/*
============================================================================
Name : 27b.c
Author:Abhishek Rauthan
Description:Write a program to execute ls -Rl by the following system calls 
b. execlp
Date: 5Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main() 
{
    execlp("ls", "ls", "-Rl", NULL);
    return 0;
}
