#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *ptr;
char criteria[40];
char result[100];
char filename[30];
char *fname = "fname";
char *sname = "Sname";
char *gender = "Gender";
char *date = "Date";
char *condition = "Condition";
char *username = "username";
char str1[30];
char str2[100];
int cases = 0;
int line = 1;
void main(){
    printf("Enter the filename:");
    scanf("%s",filename);
    ptr = fopen(filename,"r");
    if(ptr == NULL){
        perror("Error opening file, try checking the file extension or file directory.");
    exit(1);
    }else{
        puts("==========Search either by name or date==============");
       printf("\nSearch here:");
       scanf("%s",str1);
        while (fgets(str2,sizeof(str2),ptr) != NULL){
           /* code here */ 
          if((strstr(str2,str1)) != NULL){
              puts("===============================================");
            printf("%s \t%-2s %-4s %-2s \t%-14s %-15s\n",fname,sname,gender,date,condition,username);
              puts(str2);
              puts("===============================================");

              cases++;
          }
          line++;
          
        }
      
        //    no result found
        if(cases == 0){
            puts("===========No results founds============");
        }

        fclose(ptr);
    }
}