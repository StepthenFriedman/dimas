#include <stdio.h>

int main(){
    int t,i,j,n,arr[100000],hasEven;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d",&n);
        for (hasEven=-1,j=0;j<n;j++) {
            scanf("%d",&arr[j]);
            if (!(arr[j]%2)) hasEven=j;
        }
        if (n==1&&(arr[0]%2)) printf("-1\n");
        else if ((~hasEven)) printf("1\n%d\n",hasEven+1);
        else printf("2\n1 2\n");
    }
    return 0;
}