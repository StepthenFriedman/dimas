#include <stdio.h>

double power(double x,int n,double ori){
    if (n<2) return x;
    else if (n%2) return power(x,n-1,ori)*x;
    else return power(x*x,n/2,ori);
}

int main(){
    double x;int n;
    while (1){
        printf("Enter x: ");scanf("%lf",&x);
        printf("Enter power of x: ");scanf("%d",&n);
        printf("result: %g\n",power(x,n,x));
    }
    
    return 0;
}