#include<stdio.h>
int main(){
	int n,o;
    while(o=0,~scanf("%d",&n)){
		while (n-1){
            if (n%2) printf("%d ",n),o=1,n=n*3+1;
            else n/=2;
        }
        if (!o) printf("No number can be output !");
        putchar('\n');
	}
    return 0;
}