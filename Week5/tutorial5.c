/*#include <stdio.h>
#include <string.h>

typedef struct address {
    char province[50];
    char district[50];
    char city[50];
    int ward;
} add;

typedef struct Students {
    char studentName[50];
    int roll;
    int marks;
    add address;
} student;

int main() {
    student stu;

    printf("Enter name: ");
    fgets(stu.studentName, sizeof(stu.studentName), stdin);
    stu.studentName[strcspn(stu.studentName, "\n")] = '\0';
    printf("Enter roll: ");
    scanf("%d", &stu.roll);
    printf("Enter marks: ");
    scanf("%d", &stu.marks);
    getchar();
    printf("Enter province: ");
    fgets(stu.address.province, sizeof(stu.address.province), stdin);
    stu.address.province[strcspn(stu.address.province, "\n")] = '\0';
    printf("Enter district: ");
    fgets(stu.address.district, sizeof(stu.address.district), stdin);
    stu.address.district[strcspn(stu.address.district, "\n")] = '\0';
    printf("Enter city: ");
    fgets(stu.address.city, sizeof(stu.address.city), stdin);
    stu.address.city[strcspn(stu.address.city, "\n")] = '\0';
    printf("Enter ward: ");
    scanf("%d", &stu.address.ward);
    printf("\nStudent Details:\n");
    printf("Name: %s\n", stu.studentName);
    printf("Roll: %d\n", stu.roll);
    printf("Marks: %d\n", stu.marks);
    printf("Province: %s\n", stu.address.province);
    printf("District: %s\n", stu.address.district);
    printf("City: %s\n", stu.address.city);
    printf("Ward: %d\n", stu.address.ward);
}*/

#include<stdio.h>
#include<string.h>

typedef struct Students{
  char name[50];
  int roll;
  int marks;
} students;

void readInformation(students stu[]){
  for(int i = 0; i<10; i++){
    printf("Enter name: ");
    scanf("%s",&stu[i].name);
    printf("Enter roll: ");
    scanf("%d",&stu[i].roll);
    printf("Enter marks: ");
    scanf("%d",&stu[i].marks);
  }
}

void displayInformation(students stu[]){
  for(int i = 0; i<10; i++){
    printf("%s \n%d \n%d",stu[i].name, stu[i].roll, stu[i].marks);
  }
}

int main(){
  students stu[10];
  readInformation(stu);
  displayInformation(stu);
}
