#include <stdio.h>

double power(double x,int n){
    if (n<2) return x;
    else if (n%2) return power(x,n-1)*x;
    else return power(x*x,n/2);
}

int main(){
    double x;int n;
    while (1){
        printf("Enter x: ");scanf("%lf",&x);
        printf("Enter power of x: ");scanf("%d",&n);
        printf("result: %g\n",power(x,n));
    }
    return 0;
}