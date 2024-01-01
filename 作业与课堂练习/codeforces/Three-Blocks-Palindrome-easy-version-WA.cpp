#include <stdio.h>

int a[2010];

int maxDulp(int*a,int start,int end){
    if (start>=end) return 0;
    int dulp[27]={0},max=0,i;
    for (i=start;i<end;i++) dulp[a[i]]++;
    for (i=0;i<27;i++) if (max<dulp[i]) max=dulp[i];
    return max;
}

int maxDulpOutside(int*a,int start,int end,int n){
    if (start==0||end==n) return 0;
    int leftdulp[27]={0},rightdulp[27]={0},max=0,temp,i;
    for (i=0;i<start;i++) leftdulp[a[i]]++;
    for (i=end;i<n;i++) rightdulp[a[i]]++;
    for (i=0;i<27;i++) {
        temp=(leftdulp[i]&&rightdulp[i])*(leftdulp[i]+rightdulp[i]);
        if (max<temp) max=temp;
    } 
    return max;
}

int main(){
    int t,n,i,j,max,temp;
    scanf("%d",&t);
    while (t--){
        max=0;
        scanf("%d",&n);
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        if (n==1){ printf("1\n");continue;}
        for (i=0;i<n;i++) for (j=i+1;j<=n;j++) {
            temp=maxDulp(a,i,j)+maxDulpOutside(a,i,j,n);
            if (max<temp) max=temp;
        }
        printf("%d\n",max);
    }
    return 0;
}