#include <cmath>
#include <stdio.h>
#include <math.h>

long long int count(int *l,long long int len,long long int target){
    long long int seperate=0,p,sum=0;
    for (p=0;p<len;p++){
        if (l[p]) seperate++;
        else {
            if (seperate>=target) sum+=seperate-target+1;
            seperate=0;
        }
    }
    return sum;
}

int main(){
    long long int m,n,i,len,sum=0,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    int a[n],b[m];
    for (i=0;i<n;i++) scanf("%d",&a[i]); a[i]=0;
    for (i=0;i<m;i++) scanf("%d",&b[i]); b[i]=0;
    double sqt=sqrt((double)k)+0.0001;
    for (i=1;(double)i<=sqt;i++) if (!(k%i)) {
        sum+=count(a,n+1,i)*count(b,m+1,k/i);
        if ((i*i)-k) sum+=count(a,n+1,k/i)*count(b,m+1,i);
    }
    printf("%lld\n",sum);
    return 0;
}