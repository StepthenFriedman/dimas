#include <stdio.h>
int Fibonacci(int n){
    long int f[2]={0,1};
    for (int i=0;i<n;i++){
        f[i%2]=f[0]+f[1];
    }
    return f[n%2];
}
int main(){
	for (int i=0;i<100;i++) printf("%lld ",Fibonacci(i));
	return 0;
}
