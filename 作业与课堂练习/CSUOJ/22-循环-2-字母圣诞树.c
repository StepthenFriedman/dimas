#include <stdio.h>
 
int main() {
    int n,i,j,k,l;
    char ch,a;
    scanf("%d",&n);
    while(n--){
        getchar();
        scanf("%c",&ch);
        a='A';
        for(i=0;i<ch-64;i++){
            printf("%*c\n",ch-63,a);
            for(l=0;l<ch-'A'-i;l++) printf(" ");
            for(k=0;k<2*(a-64)+1;k++) printf("%c",a);
            printf("\n");
            a++;
        }
    }
    return 0;
}