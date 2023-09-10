/*
============================================================================
Name : 27c.c
Author:Abhishek Rauthan
Description:Write a program to execute ls -Rl by the following system calls 
c. execle
Date: 5Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main() {
    execle("/bin/ls", "ls", "-Rl", NULL, NULL);
    return 0;
}