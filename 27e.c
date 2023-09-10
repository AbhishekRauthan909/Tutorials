/*
============================================================================
Name : 27a.c
Author:Abhishek Rauthan
Description:Write a program to execute ls -Rl by the following system calls 
e. execvp
Date: 5Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main() {
    char *a[] = {"ls", "-Rl", NULL};
    execvp("ls", a);
    return 0;
}