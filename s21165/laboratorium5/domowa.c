#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define SLEEP_TIME 5

int main() {

int status;
printf("I am: %d\n\n", (int)getpid());
pid_t c_pid = fork(); // fork a child

if(c_pid == 0)
{
    printf("Hi I'm process C (%d) and my parent is %d\n",getpid(),getppid());
    sleep(SLEEP_TIME);
    exit(1);
}
else
{
    pid_t b_pid = fork(); // fork a child
    if (b_pid == 0)
    {
        printf("Hi I'm process B (%d) and my parent is %d.\n", getpid(), getppid());
        pid_t d_pid = fork(); // fork a child
       
        if (d_pid == 0)
        {
            printf("Hi I'm process D (%d) and my parent is %d.\n",getpid(),getppid());
            sleep(SLEEP_TIME);
            exit(3);
        }
        else
        {
            // sleep before wait - actually no effect as the wait for D also waits for SLEEP_TIME
            sleep(SLEEP_TIME);
            // Wait for D to quit
            waitpid(d_pid, &status, 0);
            int DReturnValue = WEXITSTATUS(status);
            printf("parent knows child D (%d) finished with return value %d\n\n", (int) d_pid, DReturnValue);
              pid_t f_pid = fork();
                if (f_pid == 0)
        {
            printf("Hi I'm process F (%d) and my parent is %d.\n",getpid(),getppid());
            sleep(SLEEP_TIME);
            exit(3);
        }
        
        
        else
        {
            // sleep before wait - actually no effect as the wait for D also waits for SLEEP_TIME
            sleep(SLEEP_TIME);
            // Wait for D to quit
            waitpid(f_pid, &status, 0);
            int FReturnValue = WEXITSTATUS(status);
            printf("parent knows child F (%d) finished with return value %d\n\n", (int) f_pid, FReturnValue);
        }
        exit(2);
    }
        
        }
        
        
        
       
    else
    {
      sleep(SLEEP_TIME);

      // Wait for B to quit
      waitpid(b_pid, &status, 0);
      int BReturnValue = WEXITSTATUS(status);
      printf("parent knows child B (%d) finished with return value %d\n\n", (int) b_pid, BReturnValue);

      // Wait for C to quit
                                    waitpid(c_pid, &status, 0);
      int CReturnValue = WEXITSTATUS(status);
      printf("parent knows child C (%d) finished with return value %d\n\n", (int) c_pid, CReturnValue);
      
      
      
      

      
    }
}

return 0;
}
