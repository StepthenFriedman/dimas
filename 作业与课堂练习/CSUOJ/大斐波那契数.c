#include <stdio.h>
#include <stdlib.h>

int* findRoutine(int m,int* len){
    int f[2]={0,1};
    int *routine=(int*)malloc(m*m*sizeof(int)),i;
    routine[0]=0;routine[1]=1;
    for (i=2;;i++){
        routine[i]=f[i%2]=((f[0]%m)+(f[1]%m))%m;
        if (f[!(i%2)]==0&&f[i%2]==1) {
            *len=i-1;break;
        }
    }
    return routine;
}

int power(unsigned long long x,unsigned long long n,unsigned long long ori,int m){
    if (n<2) return x;
    else if (n%2) return (power(x,n-1,ori,m)*x)%m;
    else return (power((x*x)%m,n/2,ori,m))%m;
}

int powerof(unsigned long long x,unsigned long long n,int m){
    return power(x%m,n,x%m,m);
}

int main(){
    unsigned long long a,b;
    int n,len,i;
    while (~scanf("%llu%llu%d",&a,&b,&n)){
        int*routine=findRoutine(n,&len);
        printf("%d\n",routine[(powerof(a,b,len))]);
    }
}