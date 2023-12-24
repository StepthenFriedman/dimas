#include <stdio.h>
#include <math.h>
#include <ctime>

int a[10000000];

clock_t x(){
    int i,*j,amount,sqt,*st=a;
    a[0]=2;
    clock_t start = std::clock();
    for (amount=1,i=3;i<3000000;i+=2){
        sqt=sqrt(i);
        for (j=st;*j<=sqt;j++) if (!(i%*j)) goto next;
        a[amount++]=i;
        next:;
    }
    clock_t end = std::clock();
    return end-start;
}
//83524


clock_t y(){
    int i,*j,amount,sqt,*st=a;
    a[0]=2,a[1]=3,a[2]=5;
    clock_t start = std::clock();
    for (amount=3,i=9;i<3000000;i+=6){
        sqt=sqrt(i+2);
        i-=2;
        for (j=st;*j<=sqt;j++) if (!(i%*j)) goto next1;
        a[amount++]=i;
        next1:;
        i+=4;
        for (j=st;*j<=sqt;j++) if (!(i%*j)) goto next2;
        a[amount++]=i;
        next2:;
        i-=2;
    }
    clock_t end = std::clock();
    return (end-start);
}
//81206

clock_t z(){
    int i,*j,amount,sqt,*st=&a[2];
    a[0]=2,a[1]=3,a[2]=5;
    clock_t start = std::clock();
    for (amount=3,i=7;i<3000000;i+=6){
        sqt=sqrt(i+4);
        for (j=st;*j<=sqt;j++) if (!(i%*j)) goto next1;
        a[amount++]=i;
        next1:;
        i+=4;
        for (j=st;*j<=sqt;j++) if (!(i%*j)) goto next2;
        a[amount++]=i;
        next2:;
        i-=4;
    }
    clock_t end = std::clock();
    return (end-start);
}
//7827

int main(){
    int i;clock_t sum=0;
    for (i=0;i<100;i++) sum+=z();
    printf("average time:%ld\n",sum/100);
    return 0;
}