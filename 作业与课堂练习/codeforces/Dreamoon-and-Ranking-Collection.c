#include <stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
    int t,n,i,j,x,arr[100000],res;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d%d",&n,&x);arr[0]=0;n++;
        for (j=0;j<n-1;j++) scanf("%d",&arr[j+1]);
        qsort(arr,n,sizeof(int),cmp);
        j=1;
        while (x){
            while (arr[j]<=arr[j-1]+1 && (j<n)) j++;
            if (j==n) {arr[j-1]+=x; break;}
            while (arr[j-1]<arr[j]-1&&x){
                arr[j-1]++;x--;
            }
            while (arr[j]<=arr[j-1]+1 && (j<n)) j++;
        }
        printf("%d\n",arr[j-1]);
    }
    return 0;
}
