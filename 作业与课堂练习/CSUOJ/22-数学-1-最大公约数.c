#include <stdio.h>

int check(long x){
    return x-(x/2)-(x/3)+(x/6);
}

int main(){
    long L,R,T;
    scanf("%ld",&T);
    while(T--){
        scanf("%ld%ld",&L,&R);
        printf("%d\n",check(R)-check(L-1));
    }
    return 0;
}
