/*#include<stdio.h>

int main(){
  int arr[] = {9,4,2,8,7};
  //printf("%d",arr[0]);

  //int x = sizeof(arr);
  //printf("%d \n",x);            Gived the total size of the array not the length. it gives size of address.
  
  int lengthOfArr = sizeof(arr)/sizeof(arr[0]);
  int largestNumber = 0;
  for(int i = 0; i<=lengthOfArr; i++){
    if(arr[i]>largestNumber){
      largestNumber = arr[i];
    }
  }
  printf("%d",largestNumber);
}*/
/*
#include<stdio.h>

int main(){
  int arr[] = {10,3,4,7,80,12,1};
  int greaterNum = 0;
  int lengthOfArr = sizeof(arr)/sizeof(arr[0]);

  for(int i=0;i<lengthOfArr-1;i++){
    for(int j=0; j<lengthOfArr-i-1;j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  for(int i=0;i<lengthOfArr;i++){
    printf("%d, ",arr[i]);
  }
}*/
/*
#include<stdio.h>

int main(){
  int n = 10, sum=0;
  int arr[n];
  printf("Enter %d numbers",n);

  for(int i = 0; i<n; i++){
    printf("Enter number %d",i+1);
    scanf("%d",&arr[i]);
    sum+=arr[i];
  }
  printf("%d",sum);
//  for(int i=0; i<n; i++){
//    printf("%d",arr[i]);
//  }
}*/

#include<stdio.h>

int main(){
  int arr[5][5];
  for(int i = 0; i<=5; i++){
    for(int j = 0; j<=i; j++){
      printf("Enter numbers: ");
      scanf("%d",&arr[i][j]);
    }
  }
}
