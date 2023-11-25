#include <cmath>
#include <stdio.h>
#include <math.h>

long long int count(long long int *l,long long int len,long long int target){
    long long int p,sum=0;
    for (p=0;p<len;p++) if (l[p]>=target) sum+=l[p]-target+1;
    return sum;
}

int main(){
    long long int m,n,i,j,len,sum=0,sep,k,tmp,lena,lenb;
    scanf("%lld%lld%lld",&n,&m,&k);
    long long int a[n/2+10],b[m/2+10];
    a[0]=b[0]=0;
    double sqt=sqrt((double)k)+0.0001;
    for (sep=i=j=0;i<n;i++){
        scanf("%lld",&tmp);
        if (tmp) sep++;
        else if (sep) { a[j++]=sep; sep=0;}
    }
    a[j++]=sep;lena=j;
    for (sep=i=j=0;i<m;i++){
        scanf("%lld",&tmp);
        if (tmp) sep++;
        else if (sep) { b[j++]=sep; sep=0;}
    }
    b[j++]=sep;lenb=j;
    for (i=1;(double)i<=sqt;i++) if (!(k%i)) {
        sum+=count(a,lena,i)*count(b,lenb,k/i);
        if ((i*i)-k) sum+=count(a,lena,k/i)*count(b,lenb,i);
    }
    printf("%lld\n",sum);
    return 0;
}