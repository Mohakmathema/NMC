/*#include<stdio.h>
#include<stdlib.h>

typedef struct{
  char empName[50];
  int age;
  float salary;
} empInfo;

void readInfo(empInfo EI[]){
  for(int i = 0; i<5; i++){
    printf("Enter name: ");
    scanf("%s",EI[i].empName);
    printf("Enter age: ");
    scanf("%d",&EI[i].age);
    printf("Enter salary: ");
    scanf("%f",&EI[i].salary);
  }
}

void writeInfo(empInfo EI[]){
  FILE *fptr;
  fptr = fopen("empinfo.txt","w");
  if(fptr == NULL){
    printf("Unable to open file. Program will exit");
    exit(0);
  }
  for(int i = 0; i<5; i++){
    fprintf(fptr, "%s, %d, %f \n",EI[i].empName, EI[i].age, EI[i].salary);
  }
  fclose(fptr);
}

int main(){
  empInfo EI[5];
  readInfo(EI);
  writeInfo(EI);
}*/

#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *fptr1, *fptr2;
  int c;
  fptr1 = fopen("empinfo.txt", "r");
  if(fptr1 == NULL){
    printf("File unable to open. \n");
    exit(1);
  }
  fptr2 = fopen("newempinfo.txt","w");
  if(fptr2 == NULL){
    printf("File unable to open. \n");
    exit(1);
  }
  while((c = fgetc(fptr1)) != EOF){
    fputc(c,fptr2);
  }
  fclose(fptr1);
  fclose(fptr2);
}
