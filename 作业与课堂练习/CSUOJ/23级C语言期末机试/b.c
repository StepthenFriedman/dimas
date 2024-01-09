#include <stdio.h>

int main(){
    int n,i,j;
    while (~scanf("%d",&n)){
        for (i=0;i<n;i++){
            printf("%*c",n-i,'a');
            for (j=0;j<i;j++) putchar('a'+j+1);
            if (i==n-1) for (j=i;j>0;j--) putchar('a'+j-1);
            else putchar('\n');
        }
        putchar('\n');
        for (i=n-1;i>0;i--){
            for (j=0;j<n-1;j++) putchar(' ');
            for (j=0;j<i;j++){
                putchar('a'+i-j-1);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}