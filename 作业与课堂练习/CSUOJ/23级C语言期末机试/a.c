#include <stdio.h>

int main(){
    int n;
    while (~scanf("%d",&n)){
        if (n>2&&(n%2==0)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}