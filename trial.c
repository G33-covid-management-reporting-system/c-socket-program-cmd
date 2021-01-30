#include <string.h>
#include <stdio.h>
#include <stdlib.h>
FILE *ptr;
int j,n;
void main(){
char patient[2][6][100];
char *str2 = "Mugamba";
printf("Enter the record to register:");
scanf("%d",&n);

if ((ptr = fopen("sample.txt","a")) == NULL) {
   /* code here */ perror("Error:");
                    exit(1);
}else {
   /* code here */ 
  for (int i = 0; i < n; i++) {
      for(j = 0; j< 6; j++){
 /* code here */ 
   printf("\n$ ");
   scanf("%s",patient[i][j]);
      }
  
   puts("--------------------------");

    }
    for (int i = 0; i < n; i++) {
     // for(int j = 0; j< 6; j++){
        fprintf(ptr,"%-3s %-6s %-6s %-6s %-6s %-6s\n",patient[i][0],patient[i][1],patient[i][2],patient[i][3],patient[i][4],patient[i][5]);
       //  }
     }
        fclose(ptr);
}
//char *pos = strstr(str1,str2);



}


