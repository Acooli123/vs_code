#include<stdio.h>
#include<unistd.h>
#include<sys/type.h>
int main(){
    int pid;
    pid = fork();
    if(pid<0){
        perror("fork");
        return 1;
    }
    else if(pid==0){
        printf("Child Process");
        printf("process id:%d\n",getpid());
        printf("parent id:%d\n",getppid());
    }
    else{
        printf("Parent Process");
        printf("process id:%d\n",getpid());
        printf("child id:%d\n",pid);
    }
    return 0;
}