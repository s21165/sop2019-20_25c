#include <stdio.h>
#include <stdlib.h>
 
 
typedef int (*f)(int, int);
int dodawanie(int,int);
int max(int, int);
int min(int, int);
 
int main(int argc, char** argv){
    int odp=0;
    int x;
    int y;
    f functions[]={min, max, dodawanie};
    printf("Co chcesz wykonac?\n0. minimalna liczba\n1. maksymalna liczba\n2. dodawanie\n");
    scanf("%d", &odp);
    printf("Podaj pierwsza liczbe:");
    scanf("%d",&x);
    printf("Podaj druga liczbe:");
    scanf("%d",&y);
    printf("wybrano %d\n", odp);
    if(odp==0){
        min(x,y);
    }
    if(odp==1){
        max(x,y);
    }
    if(odp==2){
        dodawanie(x,y);
    }
}
int dodawanie(int p,int d){
    int x = p+d;
    printf("%d + %d = %d\n", p, d, x);
}
int max(int p, int d){
   
    if(p>d){
        printf("max to = %d\n", p);
    }else{
        printf("max to = %d\n", d);
    }
}
int min(int p, int d){
   
    if(p>d){
        printf("min to = %d\n", d);
    }else{
        printf("min to = %d\n", p);
    }
}
