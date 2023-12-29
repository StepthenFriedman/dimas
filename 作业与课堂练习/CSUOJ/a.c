#include <stdio.h>

int gcd(int a,int b){return b?gcd(b,a%b):a;}

void reduce(int numberator,int denominator,int *reduced_numberator,int *reduced_denominator){
    int GCD=gcd(numberator,denominator);
    *reduced_numberator=numberator/GCD;
    *reduced_denominator=denominator/GCD;
}

int main(){
    int x,y;
    while(printf("enter a fraction:"),~scanf("%d/%d",&x,&y)) reduce(x,y,&x,&y),printf("In lowest terms:%d/%d\n",x,y);
}