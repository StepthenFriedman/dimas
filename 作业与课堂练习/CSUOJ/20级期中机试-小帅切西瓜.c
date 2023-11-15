#include <stdio.h>

int main(){
    int n;
    while (~scanf("%d",&n)){
        printf("%s\n",((n%2)||(n<3))?"NO":"YES");
    }
    return 0;
}