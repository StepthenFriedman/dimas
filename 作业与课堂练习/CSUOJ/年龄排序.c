#include<stdio.h>
#include<string.h>

int arr[101]={0};

int main(){
    int n,i,ipt;
    while(scanf("%d",&n)!=EOF){
        memset(arr,0,sizeof(int)*101);
        for (i=0;i<n;i++) scanf("%d",&ipt),arr[ipt]++;
        for (i=0;i<101;i++) while (arr[i]) arr[i]--,printf("%d ",i);
        putchar('\n');
	}
    return 0;
}