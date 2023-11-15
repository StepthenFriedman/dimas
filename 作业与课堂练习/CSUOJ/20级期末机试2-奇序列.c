#include <stdio.h>

int main(){
    int n,i,start,end;
    while (~scanf("%d",&n)){
        scanf("%d",&start);end=1;
        for (i=1;i<n;i++) scanf("%d",&end);
        if ((n%2)&&(start%2)&&(end%2)) printf("Yes\n");
        else printf("No\n");
    }
    
}