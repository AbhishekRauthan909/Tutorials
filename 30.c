/*
============================================================================
Name : 30.c
Author:Abhishek Rauthan
Description:Write a program to run a script at a specific time using a Daemon process.
Time->
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include<fcntl.h>
int main(){
	if(!fork()){
		printf("the child process with %d process id will be made the daemon process\n", getpid());
		umask(0);
        	pid_t pid, setid;
       		pid=getpid();
       		setid=setsid();
		chdir("/");
        time_t curr,dead;
        struct tm *deadline;
        time(&curr);
        deadline=localtime(&curr);
        //comvert into local time zone
        deadline->tm_hour=21;
        deadline->tm_min=28;
        deadline->tm_sec=0;
        dead=mktime(deadline);
        do
        {
            time(&curr);
        } while (difftime(dead,curr)>0);
        int fd=open("/Users/abhishekrauthan/Documents/Practice ss/30/hello.txt", O_RDWR | O_APPEND);
		char buff[5]="abcg";
		write(fd, buff, strlen(buff));
        }
	else{
		printf("the parent process with %d process id is terminated\n", getpid());
		return 1;
	}
	return 0;
}