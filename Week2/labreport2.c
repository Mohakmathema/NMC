/*#include<stdio.h>
#include<math.h>

void cubeOfNum(int num){
  int cubeNum = pow(num,3);
  printf("The Cube of %d is %d",num,cubeNum);
}

int main(){
  cubeOfNum(3);
}*/
/*
#include<stdio.h>

void swapNumbers(int *num1, int *num2){
  int temp;
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int main(){
  int a,b;
  printf("Enter two numbers separated by a comma: ");
  scanf("%d,%d",&a,&b);
  swapNumbers(&a,&b);
  printf("Swapped Numbers are %d, %d",a,b);
}*/
/*
#include<stdio.h>
#include<math.h>

void checkArmstrong(int num){
  int originalNum = num;
  int value = 0;
  while(num>0){
    int modulo = num%10;
    value +=pow(modulo,3);
    num /=10;
  }
  if(value==originalNum){
    printf("The number %d is Armstrong \n",originalNum);
  }
  else{
    printf("The number is %d not Armstrong \n",originalNum);
  }
}

void checkPerfectNum(int num1){
  int originalNum = num1;
  int sum = 0;
  int check;
  for(int i = 1; i<=num1/2;i++){
    check = num1%i;
    if(check==0){
      sum+=i;
    }
  }
  if(sum==originalNum){
    printf("%d is perfect number \n",originalNum);
  }
  else{
    printf("%d is not a perfect number \n",originalNum);
  }
}

int main(){
  checkArmstrong(123);
  checkArmstrong(153);
  checkPerfectNum(6);
  checkPerfectNum(21);
  checkPerfectNum(28);
}*/
/*
#include<stdio.h>
#include<math.h>
double velocityCalc(double v, double u, double a, double t){
  if(isnan(u)){
    u = (v-a)/t;
    printf("The initial velocity is: %lf\n",u);
  }
  else if(isnan(a)){
    a = (v-u)/t;
    printf("The acceleration is: %lf\n",a);
  }
  else if(isnan(t)){
    t = (v-u)/a;
    printf("The time taken is: %lf\n",t);
  }
  else{
    double v = u+a*t;
    printf("The final velocity is: %lf\n",v);
  }
}

int main(){
  double v, u, a, t;
    int nanCount = 0;

    // Ask the user to input all values
    printf("Enter final velocity (v) [Enter NAN if unknown]: ");
    scanf("%lf", &v);
    if (isnan(v)) nanCount++;

    printf("Enter initial velocity (u) [Enter NAN if unknown]: ");
    scanf("%lf", &u);
    if (isnan(u)) nanCount++;

    printf("Enter acceleration (a) [Enter NAN if unknown]: ");
    scanf("%lf", &a);
    if (isnan(a)) nanCount++;

    printf("Enter time (t) [Enter NAN if unknown]: ");
    scanf("%lf", &t);
    if (isnan(t)) nanCount++;

    // Ensure only one value is NAN
    if (nanCount > 1) {
        printf("Error: Only one value can be NAN. Please try again.\n");
    } else if (nanCount == 0) {
        printf("Error: No value is NAN. Nothing to calculate.\n");
    } else {
        // Call the function to calculate and display the result
        velocityCalc(v, u, a, t);
    }
}*/

#include<stdio.h>
#include<math.h>
//using crammers rule
void equations(double a, double b, double c, double d, double e, double f){
  //ax+by = c
  //dx+ey = f
  double determinant1 = (a*e)-(b*d);

  if(determinant1 == 0){
    printf("This has no unique solutions");
    return;
  }

  double determinant_of_x = (c*e)-(b*f);
  double determinant_of_y = (a*f)-(c*d);

  double x = determinant_of_x/determinant1;
  double y = determinant_of_y/determinant1;

  printf("%lf, %lf ",x,y);

}
int main(){
  equations(10,20,30,10,15,25);
}

