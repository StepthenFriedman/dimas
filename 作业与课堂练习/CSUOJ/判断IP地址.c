#include <stdio.h>

int main(){
    long long ip[4];int res,i;
    while (~scanf("%lld.%lld.%lld.%lld",&ip[0],&ip[1],&ip[2],&ip[3])){
        res=1;
        for (i=0;i<4;i++) if (ip[i]<0||ip[i]>255) res=0;
        printf("%s\n",res?"Yes":"No");
    }
    return 0;
}