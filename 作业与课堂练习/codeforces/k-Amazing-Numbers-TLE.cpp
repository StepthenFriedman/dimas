#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int main(){
    int t,n,i,j,k,min,temp,ipt;
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        int *a=(int*)malloc(sizeof(int)*(n+1));
        int *maxlen=(int*)calloc(n+1,sizeof(int));
        int *temp=(int*)malloc((n+1)*sizeof(int));
        memset(temp,-1,(n+1)*sizeof(int));
        for (i=0;i<n;i++){
            scanf("%d",&ipt);
            if (maxlen[ipt]<i-temp[ipt]) maxlen[ipt]=i-temp[ipt];
            temp[ipt]=i;
        }
        for (j=0;j<=n;j++) {
            if (maxlen[j]&&maxlen[j]<i-temp[j]) maxlen[j]=i-temp[j];
        }
        for (k=1;k<=n;k++){
            min=INT_MAX;
            for (i=0;i<n;i++) if (maxlen[i]&&maxlen[i]<=k) {
                if (min>i) min=i;
            }
            if (min!=INT_MAX) printf("%d ",min);
            else printf("-1 ");
        }
        putchar('\n');
    }
    return 0;
}