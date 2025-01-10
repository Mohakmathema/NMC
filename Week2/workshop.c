/*#include<stdio.h>

void midpoint(double x1, double x2, double y1,double y2){
  double xmid = (x1+x2)/2;
  double ymid = (y1+y2)/2;

  printf("%lf, %lf",xmid,ymid);
}

int main(){
  midpoint(10,20,30,40);
}*/
/*
#include<stdio.h>

int greatest(int a, int b){
  if(a>b){
    printf("%d is greater",a);

  }
  else{
    printf("%d is greater",b);
  }
}

int main(){
  greatest(10,20);
}*/
/*
#include<stdio.h>

int triangular(int a){
  for(int i =1; i<a; i++){
    printf("%d\n",i*(i+1)/2);
  }
}

int main(){
  triangular(5);
}*/
/*
#include<stdio.h>
#include<math.h>
double velocityCalc(double v, double u, double a, double t){
  if(isnan(u)){
    u = (v-a)/t;
    printf("%lf\n",u);
  }
  else if(isnan(a)){
    a = (v-u)/t;
    printf("%lf\n",a);
  }
  else if(isnan(t)){
    t = (v-u)/a;
    printf("%lf\n",t);
  }
  else{
    double v = u+a*t;
    printf("%lf\n",v);
  }
}

int main(){
  velocityCalc(NAN,50,3,10);
  velocityCalc(12.5,NAN,3,10);
  velocityCalc(12.5,50,NAN,10);
  velocityCalc(12.5,50,3,NAN);
}*/

#include<stdio.h>
#include<math.h>

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
