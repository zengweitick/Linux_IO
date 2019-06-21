#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

//生成空洞文件
char *buffer="01234546789";


int main(int argc,char *argv[])
{
   if(argc<2)
   {
	   fprintf(stderr,"Usage :%s [file]\n",argv[0]);
	   exit(1);
   }
   int fd=open(argv[1],O_WRONLY | O_CREAT | O_TRUNC,0777);
   if(fd<0)
   {
	   perror("open error");
	   exit(1);
   }
   size_t size=strlen(buffer)*sizeof(char);
   if(write(fd,buffer,size)!=size)
   {
	   perror("error");
	   exit(1);
   }

   if(lseek(fd,10,SEEK_END)<0)
   {
	   perror("lseek error");
	   exit(1);
   }

   if(write(fd,buffer,size)!=size)
   {
	   perror("error");
	   exit(1);
   }
   close(fd);
   return 0;


}
