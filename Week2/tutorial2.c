//Task-1
/*#include<stdio.h>

void myFunction(){
  printf("Function");
}

int main(){
  myFunction();
}
*/
/*
//Task-2

#include<stdio.h>

int square(int num){
  int sq = num*num;
  printf("%d",sq);
}

int main(){
  square(10);
}*/
/*
#include<stdio.h>

int swapNumbers(int* num1,int* num2){
  int storage = *num1;
  
  //printf("%d",*storage);
  *num1 = *num2;

  *num2 = storage;
  printf("%d, %d",*num1,*num2);
}

int main(){
  int a = 10;
  int b = 20;
  swapNumbers(&a,&b);
}*/
/*
#include<stdio.h>

int evenOrOdd(int num){
  if(num%2==0){
    printf("Even");
  }
  else{
    printf("Odd");
  }
}

int main(){
  evenOrOdd(10);
}
*/
  
#include<stdio.h>

void toBinary(int num){
  int binary[32];
  int index = 0;

  while(num>0){
    binary[index]= num%2;
    num/=2;
    index++;
  }

  for(int i = index-1; i>=0; i--){
    printf("%d",binary[i]);
  }
}

int main(){
  toBinary(123);
}
