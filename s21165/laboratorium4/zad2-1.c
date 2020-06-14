#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
	FILE *fp1;
	int cnt = 0;
	int i   = 0;
	int first=0;
	


    if( argc < 2 )
    {
        printf("Insufficient Arguments!!!\n");
        printf("Please use \"program-name file-name\" format.\n");
        return -1;
    }
     
    fp1 = fopen(argv[1],"r");
    if( fp1 == NULL )
    {
        printf("\n%s File can not be opened : \n",argv[1]);
        return -1;
    }
     	

  
   	 fscanf(fp1, "%d", &first);
	printf(" number is: %d\n", first);
   	 



    fseek(fp1,0,SEEK_END);
   
    cnt = ftell(fp1);
	
printf(" file number is: %d\n", cnt);
     
    while( i < cnt && i <= first*2)

    {
	
        i++;
        fseek(fp1,-i,SEEK_END);
        printf("%c",fgetc(fp1));
    }
    printf("\n");
    fclose(fp1);
     
    return 0;
}
