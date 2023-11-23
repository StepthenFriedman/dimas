#include <stdio.h>

int good(int* h,int* t){
    if (h==t) return 0;
    if (h+1==t&&*h) return 1;
    int sum=0,len,*q,*p;
    len=t-h;
    for (p=h;p<t;p++){
        if (!*p) return good(h,p)+good(p+1,t);
        sum=*p;
        for (q=p+1;q<t;q++){
            sum+=*q;
            if (!sum) {
                if (p==h&&q==t-1) return (len*(len+1)/2)-1;
                if (q-p>1) return good(h,q)-good(p+1,q)+good(p+1,t);
                return good(h,p+1)+good(q,t);
            }
        }
    }
    return len*(len+1)/2;
}

int a[300000];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%d\n",good(&a[0],&a[n]));
    return 0;
}