#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
 
int main (){
    pid_t p= fork();
    if(p==0){
        printf("dziecko: %d rodzic: %d\n", getpid(), getppid());
        fflush(stdout);
        sleep(3);
    }
    else{
        printf("To ja: %d moj rodzic: %d dziecko: %d\n", getpid(), getppid(), p);
        fflush(stdout);
        wait(NULL);
        printf("Rodzic koniec \n");
        fflush(stdout);
}
    return 0;
} 
