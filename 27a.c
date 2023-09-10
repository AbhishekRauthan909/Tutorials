/*
============================================================================
Name : 27a.c
Author:Abhishek Rauthan
Description:Write a program to execute ls -Rl by the following system calls 
a. execl
b. execlp
c. execle
d. execv 
e. execvp
Date: 5Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main() {
    execl("/bin/ls", "ls", "-Rl", NULL);
    return 0;
}

