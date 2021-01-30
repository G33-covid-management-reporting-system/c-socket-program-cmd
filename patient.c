#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int executeCommand(char cmd[100]); // function prototype
void storePatientData(int choice); // function prototype
// file pointer
FILE *ptr;

int cas = 0;
char filename[30],district[20],condition[20],gender[10],date[30],fname[30],sname[30],username[40];
char patient[7][100];
char patientlist[row][elems][size];
int flag = 0 , cases;
char choice[100];

char criteria[40];
char results[100];
char str1[30];
char str2[100];
int cs = 0;
char check;
int line = 1;

void main(){
   printf("\n***********Welcome to Covid-19 Management and Reporting System*****************\n");
   puts("Use the following commands in order to use the system");
   puts("$ Addpatient (One patient at a time).");
   puts("$ Addpatient-list (Store multiple patients)");
   puts("$ Check_status");
   puts("$ Search filename.txt");
   puts("Enter your command:");
printf("$ ");
   scanf("%s",choice);
   executeCommand(choice);
//    Store patients.
  int result =  executeCommand(choice);
  //printf("%d\n",result);
   storePatientData(result);
}

// patients data
int executeCommand(char cmd[100]){
    if(strcmp("Addpatient",cmd) == 0){
        return 1;
    }else if (strcmp("Addpatient-list",cmd) == 0){
        return 2;
    } else if (strcmp("Check_status",cmd) == 0) {
        return 3;
    } else if (strcmp("Search",cmd) == 0){
        return 4;
    } else {
        return 5;
    }
}

void storePatientData(int choice){
       switch (choice){
        case 1:
            printf("Enter your username:");
            scanf("%s",patientlist[5]);

            printf("Enter your district:");
            scanf("%s",patientlist[6]);
            // Store one patient data.
             printf("\nEnter your patient's name eg::(mugamba bruno):");
            scanf("%s %s",patientlist[0],patientlist[1]);

            printf("\nEnter patient's gender:");
            scanf("%s",patientlist[2]);

             printf("\nEnter the date of confirmation eg(dd-mm-yy):");
            scanf("%s",patientlist[3]);

            printf("\nEnter the patient's condition eg(symptomatic or asymptomatic):");
            scanf("%s",patientlist[4]);
             printf("\n***********You have successfuly added one patient***************\n");
        break;

    case 2:
             printf("\nEnter the file name eg::(example.txt):");
             scanf("%s",filename);

            printf("Enter the number of patients to store in the file:");
            scanf("%d",&cases);

            ptr = fopen(filename,"w");

            if(ptr == NULL){
                perror("Error in creating the file!");
                exit(1);

            }else{
                // health official's information
                    printf("\n***********Health Official's Data***********\n");

                printf("\nEnter your username:");
                    scanf("%s",username);

                    printf("\nEnter your home district:");
                    scanf("%s",district);
                printf("\n***************************************\n");
                while(flag < cases && !feof(stdin)){
                    printf("\n***********Patient record[%d]***********\n",flag+1);
                    printf("\nEnter your patient's name eg::(mugamba bruno):");
                    scanf("%s %s",fname,sname);

                    printf("\nEnter patient's gender:");
                    scanf("%s",gender);

                    printf("\nEnter the date of confirmation eg(dd-mm-yy):");
                    scanf("%s",date);

                    printf("\nEnter the patient's condition eg(symptomatic or asymptomatic):");
                    scanf("%s",condition);

                    // Storing the data into the file.
                    fprintf(ptr,"%s %-2s %-4s %-2s %-4s %-2s\n",fname,sname,gender,date,condition,username);
                    printf("\n***********************************************************************\n");
                    flag++;
                }
                    printf("\n***********You have successfull stored %d patients in %s.**************\n",cases,filename);

            }
        break;

        case 3:
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
                cas++; // Incrementing every after a new line.
            }
        }
            
            printf("\n******You have %d cases registered in %s .********\n",cas,filename);
            fclose(ptr);
    }
        break;

//  Searching in the file
        case 4:
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
            //printf("%s \t%-2s %-4s %-2s \t%-14s %-15s\n",fname,sname,gender,date,condition,username);
              puts(str2);
              puts("===============================================");

              cs++;
          }
          line++;
          
        }
      
        //    no result found
        if(cs == 0){
            puts("===========No results founds============");
        }

        fclose(ptr);
    }
        break;

        case 5:
        puts("======Enter a valid command=========");
        break;
    }
}