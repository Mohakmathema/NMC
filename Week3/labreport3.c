/*#include<stdio.h>

void largestAndSmallest(int arr[], int lengthOfArr, int *largest, int *smallest){
  if(lengthOfArr<=0){
    printf("The Array is empty. There is no largest or smallest nunmber.");
  }
  *largest = *smallest = arr[0];
  for(int i = 1; i<=lengthOfArr; i++){
    if(arr[i]> *largest){
      *largest = arr[i];
    }
    else if(arr[i]< *smallest){
      *smallest = arr[i];
    }
  }
}

int main(){
  int array[] = {1,2,3,4,7,0,9,3,2,1};
  int lengthOfArr = sizeof(array)/sizeof(array[0]);
  int largest, smallest;
  largestAndSmallest(array, lengthOfArr, &largest, &smallest);
  printf("Largest: %d \n",largest);
  printf("Smallest: %d \n",smallest);
  }
*/
/*
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define ascii_size 256

bool isAnagram(char str1[], char str2[]){
//checking if the length of the strings are equal or not usgn strlen() function
  if(strlen(str1) != strlen(str2)){
    return false; //returning false if the conditions are met
  }
  int count[ascii_size] = {0};
  //looping through both the strings at the same time and stops the code after encountering a null terminator
  for(int i = 0; str1[i] && str2[i]; i++){
    count[(unsigned char)str1[i]]++; //increasing str1 and decreasing str2 to make sure the count is 0 to be anagram
    count[(unsigned char)str2[i]]--;
  }

  for(int i = 0; i<ascii_size; i++){
    if(count[i] !=0){
      return false;
    }
  }
  return true;
}

int main(){
  char str1[100], str2[100];
  printf("Enter two Strings: ");
  scanf("%s %s",str1,str2); //no need of & as string are non primitive and pointers in nature
  if(isAnagram(str1,str2)){
    printf("The string's are anagram \n");
  }
  else{
    printf("The string's are not anagram \n");
  }
}*/
/*
#include<stdio.h>

void uniqueElements(int arr[],int length){
  int index = 0;    //index for new elements
  int newArr[length]; //new array to store unique elements
  for(int i = 0;i<length;i++){
    int isUnique = 1;
    for(int j = 0; j<index;j++){
      if(arr[i] == newArr[j]){
        isUnique = 0; //if not unique set isUnique to 0
        break;
      }
    }
    if(isUnique){
      newArr[index] = arr[i];
      index++;
    }
  }

  printf("All unique elements are: ");
  for(int i = 0; i<index; i++){
    printf("%d ",newArr[i]);
  }
}

int main(){
  int a[ ] = {1,2,4,8,4,2,4,9,6};
  int length = sizeof(a)/sizeof(a[0]); 
  uniqueElements(a,length);
}*/
/*
#include<stdio.h>

void sortArray(int arr[], int length){
  int ascending;
  if(length<=0){
    printf("Array doesnot exist!");
  }
  else{
    for(int i = 0; i<length; i++){
      for(int j = i+1; j<length; j++){
        if(arr[i]>arr[j]){
          ascending = arr[i];
          arr[i] = arr[j];
          arr[j] = ascending;
        }
      }
    }
    printf("Numbers in an ascending order: \n");
    for(int i = 0; i<length; i++){
      printf("%d ",arr[i]);
    }
  }
}

int main(){
  int array[] = {6,7,3,4,9,0,11,34,2,2};
  int length = sizeof(array)/sizeof(array[0]);
  sortArray(array, length);
}*/
/*
#include<stdio.h>

int main(){
  int arr[] = {1,2,3,45,10,15,25,35,50,55,75};
  int length = sizeof(arr)/sizeof(arr[0]);
  //printf("Count is: %d \n",length);

  int sum=0;
  int count = 0;
  for(int i = 0; i<length;i++){
    if(arr[i]%5==0 && arr[i]%2!=0 && arr[i]%3!=0){
      printf("Number: %d at index: %d \n",arr[i],i);
      sum+=arr[i];
      count++;
    }
  }
  printf("Sum: %d \n",sum);
  printf("Count of such number: %d",count);
}*/

#include<stdio.h>

void readMatrix(int rows, int columns, int matrix[rows][columns]){
  printf("Enter the elements of matrix (%d x %d)",rows,columns);
  for(int i = 0; i<rows;i++){
    for(int j = 0; j<columns; j++){
      printf("Enter elements %d %d",i,j);
      scanf("%d",&matrix[i][j]);
    }
  }
}

void displayMatrix(int rows, int columns, int matrix[rows][columns]){
  for(int i = 0; i<rows;i++){
    for(int j = 0; j<columns;j++){
      printf("%d",matrix[i][j]);
    }
    printf("\n");
  }
}

void addMatrix(int rows, int columns, int matrix1[rows][columns], int matrix2[rows][columns], int result[rows][columns]){
  for(int i = 0; i<rows;i++){
    for(int j = 0; j<columns; j++){
      result[i][j] = matrix1[i][j]+matrix2[i][j];
      printf("%d",result[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int row1, column1, row2, column2;
  printf("Enter the dimensions of the matrix: ");
  scanf("%d%d",&row1,&column1);
  printf("Enter the dimensions of the second matrix: ");
  scanf("%d%d",&row2,&column2);

  if(row1!=row2 || column1!=column2){
    printf("Matrix cannot be added!");
  }
  else{
    int matrix1[row1][column1];
    int matrix2[row2][column2];
    int result[row1][column2];

    readMatrix(row1,column1,matrix1);
    readMatrix(row2,column2,matrix2);
    addMatrix(row1,column1,matrix1,matrix2,result);

    printf("matrix after addition: \n");
    displayMatrix(row1,column1,result);
  }
}
