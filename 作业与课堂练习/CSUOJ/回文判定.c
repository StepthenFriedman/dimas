#include<stdio.h>
#include<string.h>

char a[100000];
int main(){
    int len,i,j;
	while(scanf("%s",&a)!=EOF){
        len=strlen(a);
        for (i=0;i<len;i++) if (a[i]!=a[len-1-i]){
            printf("No!\n");goto end;
        }
        printf("Yes!\n");
        end:;
	}
	return 0;
}