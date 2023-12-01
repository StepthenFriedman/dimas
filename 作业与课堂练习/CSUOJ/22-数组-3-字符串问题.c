#include<stdio.h>

int main(){
    int n,m,i,x;
    scanf("%d %d",&n,&m);
	char str[n+2];
	int arr[26]={0},res[n+1];
	scanf("%s",str);
	for (i=0;str[i]!='\0';i++){
		arr[str[i]-97]++;
		res[i+1]=arr[str[i]-97];
	}
	for(i=0;i<m;i++){
		scanf("%d",&x);
		printf("%d\n",res[x]);
	}
    return 0;
}