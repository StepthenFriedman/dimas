#include<stdio.h>

int arr[10000]={0};

int main(){
	char c;int i=0;
    while(scanf("%d",&arr[i++])!=EOF){
		if(scanf("%c",&c)==EOF||c=='\n'){
			for (i--;i>-1;i--) printf("%d ",arr[i]);
		    putchar('\n');
			i=0;
		}
	}
    return 0;
}

