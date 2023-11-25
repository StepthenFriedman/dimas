#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 500000
 int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
 }
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long int n;
        scanf("%lld",&n);
        int arr[MAX],temp=0,mid=0,rea=0;
        for(int i=0;i<=n;i++){
            arr[i]=0;
        }
        for(int i=1;i<=n;i++){
            mid=n/i;if(mid!=arr[rea]){rea=temp;arr[temp++]=mid;}
        }
        int length=strlen(arr);
        qsort(arr,length,sizeof(int),cmp);
        printf("%d\n",length+1);
        printf("0 ");
        for(int j=0;j<length;j++){
            printf("%d",arr[j]);
        }
        printf("\n");
    }
    return 0;
}