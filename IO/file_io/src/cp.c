#include<stdio.h>
#include "io.h"
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main(int argc ,char *argv[])
{
	if(argc!=3)
	{
		perror("input error!!!");
			exit(1);
	}
     int fdin,fdout;
	 fdin=open(argv[1],O_RDONLY);
	 if(fdin<0)
	 {
		 perror("open fdin error\n");
	     exit(1);
	 }
	 fdout=open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0777);

     if(fdout<0)
	 {
		 perror("open fdout error\n");
		 exit(1);
	 }
     copy(fdin,fdout);
	 close(fdin);
	 close(fdout);
	 return 0;
}
