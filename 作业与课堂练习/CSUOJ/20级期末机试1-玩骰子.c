#include <stdio.h>
int tenth(int i){
	int res=1;
	while(i){i--;res*=10;}
	return res;
}

int digit(int x,int i){
	if (i==-1) return 0;
	else return (x/tenth(i))-((x/tenth(i+1))*10);
}

int main(){
    int T,dice,m,n,k,i;
    while (~scanf("%d",&T)){
        while (T--){
            int arr[7]={0};
            scanf("%d%d",&dice,&m);
            for (i=0;i<6;i++) arr[digit(dice,i)]++;
            for (i=1;i<=m;i++){
                scanf("%d%d",&n,&k);
                printf("%d:",i);
                if (((k!=1)*arr[k])+arr[1]>=n) printf("true\n");
                else printf("false\n");
            }
            putchar('\n');
        }
    }
}