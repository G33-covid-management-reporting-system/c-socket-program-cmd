#include <stdio.h>
#include <stdlib.h>
FILE *ptr;
char filename[60];
char check;
int case = 0;

void main(){
    printf("\n*********Check File Status*********\n");
    // Entering the filename.
    printf("Enter the file name(example.txt):");
    scanf("%s",filename);

// opening the file for checking

    ptr = fopen(filename,"r");
    if(ptr == NULL){
        perror("Failed to open file, check the directory or file extension");
        exit(1);
    }else{
        // scanning through the file.
        for(check = getc(ptr); check != EOF; check = getc(ptr)){
        if(check == '\n'){
                cases++; // Incrementing every after a new line.
            }
        }
            
            printf("\n******You have %d cases registered in %s .********\n",cases,filename);
            fclose(ptr);
    }
    // printf("Hi from ubuntu 20.10");

}