#include <stdio.h>

int main(){
    int t,n,i,j,red[1000],blue[1000];
    char ipt[1000];
    for (i=0;i<t;i++){
        scanf("%d%s",&n,&ipt);
        for (j=0;j<n;j++) scanf("%d",&red[j]);
        for (j=0;j<n;j++) scanf("%d",&blue[j]);
    }

    return 0;
}