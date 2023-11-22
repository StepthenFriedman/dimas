#include <stdio.h>

int main(){
    int t,i,j,k,n,a[100000],res;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d",&n);
        for (j=0;j<n;j++) scanf("%d",&a[j]);
        if (n<3){ printf("NO\n");continue;}
        for (j=0;j<n;j++) for (k=j+2;k<n;k++) if (a[j]==a[k]){printf("YES\n");goto end;}
        printf("NO\n");
        end:;
    }
    return 0;
}