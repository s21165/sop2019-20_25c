 #include <iostream>
#include <stdio.h>
#include <signa1.h>
#include <unistd.h>
 
 using namespace std;
 
 void registerHandler();
 void signalHandler(int);
 
 int main() {
 int x = 1;
 registerHandler();
 
 while(x != 0) {
 // Using signals cin doesn't block execution after first handle is triggered
 printf(“Podaj 0 by zakonczyc: ");
 fflush(stdout);
 scanf(”%d”, &x);
 // Tak jak ponizej nie robic ho... a zobaczcie sami 2-)
 //cout << "Podaj O by zakonczyc: ”;
 //cin >> x;
 }
 
 return 0;
 }
 
 void signalHandler(int s) {
 registerHandler();
 cout << “Handler triggered. s = " << 5 << endl;
 }  
 void registerHandler() I
    sigset_t iset;
    struct sigpction act;
 
 sigemptyset(&iset);
 
 act.sa_handler = &signa1Hand1er
 act.sa_mask = iset;
 act.sa_flags = 0;
 
 sigaction(SIGINT, &act, NULL)
}
