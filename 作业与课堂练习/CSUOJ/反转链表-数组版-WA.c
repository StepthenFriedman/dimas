#include<stdio.h>

int arr[10000]={0};

int main(){
	char last;
	int i,j;
    nextline:i=0;
    nextword:scanf("%d",&arr[i++]);
    last=getchar();
    if (last==' ') goto nextword;
    else if (last=='\n'){
    	for (j=i-1;j>-1;j--) printf(" %d"+!(j-i+1),arr[j]);
		putchar('\n');
    	goto nextline;
	} 
    return 0;
}

