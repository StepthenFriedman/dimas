#include <stdio.h>

int isPal(char* a, char* b, int n){
    for (int i=0;i<n;i++) if (a[i]!=b[n-i-1]) return 0;
    return 1;
}

int main(){
    int t,n,i,j,k;
    char ipt[200][60];
    int palStart[200],palEnd[200];
    while (~scanf("%d%d",&t,&n)){
        for (i=0;i<t;i++) scanf("%s",&ipt[i]); k=0;
        for (i=0;i<t;i++) for (j=i;j<t;j++) if (isPal(ipt[i],ipt[j],n)) {
            palStart[k]=i;palEnd[k++]=j;
        for (i=0;i<k;i++) printf("[ %d - %d ]\n",palStart[i],palEnd[i]);
    }
    //printf("%d",isPal("tab","tab",3));

    return 0;
}