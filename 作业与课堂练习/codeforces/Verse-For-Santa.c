#include <stdio.h>

int main(){
    int maxarr[200000],maxindx[200000];
    int t,n,i,j,k,s,arr[200000];long long int sum;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d%d",&n,&s);
        for (maxindx[0]=sum=j=0;j<n;j++){
            scanf("%d",&arr[j]);
            if (j) {
                maxarr[j]=arr[j]>maxarr[j-1]?arr[j]:maxarr[j-1];
                maxindx[j]=arr[j]>maxarr[j-1]?j:maxindx[j-1];
            }
            else maxarr[0]=arr[0];
            sum+=arr[j];
        }
        //for (j=0;j<n;j++) printf("%d ",maxarr[j]);
        for (k=j;k>0&&(sum-maxarr[k-1])>s;k--,sum-=arr[k]);
        if (s>=sum) printf("0\n");
        else printf("%d\n",maxindx[k-1]+1);
    }
    return 0;
}