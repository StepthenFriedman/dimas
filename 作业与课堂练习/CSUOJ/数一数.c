#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char **ipt=(char**)malloc(100*100*sizeof(char*));
    int *count=(int*)calloc(1000,sizeof(int));
    int i,j,k,n,max,indx,ok;
    scanf("%d",&n);
    for (max=indx=i=k=0,ok=1;i<n;i++){
        char *temp=(char*)malloc(100*sizeof(char));
        scanf("%s",temp);
        for (j=0;j<k;j++) if (!strcmp(ipt[j],temp)) {count[j]++;goto next;}
        count[k]++;
        ipt[k++]=temp;
        next:;
    }
    for (i=0;i<k;i++) {
        if (max<count[i]) max=count[i],indx=i;
        if (count[i]%2||count[i]==2) ok=0;
    }
    printf("%s\n%s\n",ipt[indx],ok?"yes":"no");
    return 0;
}
