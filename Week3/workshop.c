/*#include<stdio.h>

int main(){
  int *a, *b, x, y;
  printf("Enter two numbers separated by a comma: ");
  scanf("%d, %d",&x,&y);
  a = &x;
  b = &y;
  if(*a>*b){
    printf("%d is greater",*a);
  }
  else{
    printf("%d is greater",*b);
  }
}*/
/*
#include<stdio.h>

int main(){
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int count = sizeof(arr)/sizeof(arr[0]);
  printf("Count is: %d \n",count);

  int sum=0;
  for(int i = 0; i<=count;i++){
    if(arr[i]/7==0 && arr[i]/2!=0 && arr[i]/3!=0){
      sum+=arr[i];
    }
  }
  printf("Sum: %d \n",sum);
}*/
/*
#include<stdio.h>

void arrFunc(int arr[], int size, int target){
  for(int i = 0; i<size; i++){
    if(arr[i]==target){
      printf("Found the element in %d",i);
      return;
    }
  }
  printf("Element not found");
}

int main(){
  int array[] = {10, 5, 7, 91, 54, 24};
  int size = sizeof(array)/sizeof(array[0]);
  int element;
  printf("Enter an element: ");
  scanf("%d",&element);
  arrFunc(array,size,element);
}*/
/*
#include<stdio.h>

void largest(int arr[]){
  if(arr[0]>arr[1] &&arr[0]>arr[2]){
    printf("%d is greatest",arr[0]);
  }
  else if(arr[1]>arr[0] && arr[1]>arr[2]){
    printf("%d is greatest",arr[1]);
  }
  else{
    printf("%d is greatest",arr[2]);
  }
}

int main(){
  int array[3];
  printf("Enter 3 numbers separated by a comma: ");
  scanf("%d,%d,%d",&array[0],&array[1],&array[2]);
  largest(array);
}*/
/*
#include <stdio.h>

void swapNumbers(int *num1, int *num2, int *num3){
  int temp1, temp2, temp3;
  temp1 = *num1;
  temp2 = *num2;
  temp3 = *num3;
  *num1 = temp3;
  *num2 = temp1;
  *num3 = temp2;

  printf("%d, %d, %d",*num1, *num2, *num3);
}

int main(){
  int a,b,c;
  printf("Enter three numbers separated by a comma: ");
  scanf("%d,%d,%d",&a,&b,&c);
  swapNumbers(&a,&b,&c);
}*/
/*
#include<stdio.h>

void calc(int *num1, int *num2, int *num3){
  int sum = *num1 + *num2 + *num3;
  int multiplication = *num1 * *num2 * *num3;
  int subtract = *num3 - *num2 - *num1;
  int quotient = *num1/ *num2/ *num3;
  printf("%d \n",sum);
  printf("%d \n",multiplication);
  printf("%d \n",subtract);
  printf("%d \n",quotient);

  if(*num1<*num2 && *num1<*num3){
    printf("%d is minimum",*num1);
  }
  else if(*num2<*num1 && *num2<*num3){
    printf("%d is minimum",*num2);
  }
  else{
    printf("%d is minimum",*num3);
  }
  printf("\n");
}

int main(){
  int a,b,c;
  printf("Enter three numbers with comma: ");
  scanf("%d,%d,%d",&a,&b,&c);
  calc(&a,&b,&c);
}*/

#include<stdio.h>

void replace(int arr[], int size){
  for(int i = 0; i<size; i++){
    arr[i] = 5;
  }
}

int main(){
  int size;
  int array[size];
  printf("Enter the size/length of the array you'd like: ");
  scanf("%d",&size);
  printf("Enter %d elements for the array:\n", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
   printf("Array before replacement: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
  replace(array,size);

   printf("Array after replacement: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
