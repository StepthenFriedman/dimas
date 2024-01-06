#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int main(){
    int n,i,ipt,len=0;
    char* count=(char*)calloc(MAX,sizeof(char));
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&ipt);
        if (!count[ipt]) len++,count[ipt]=1;
    }
    printf("%d\n",len);
    for (i=0;i<MAX;i++) if (count[i]) printf("%d ",i);
    putchar('\n');
    return 0;
}