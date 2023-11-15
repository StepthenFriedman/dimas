#include <stdio.h>

int main(){
    int num,w,i;
    while (1) {
        printf("Enter number of days in month: ");scanf("%d",&num);
        printf("Enter starting day of the week (1=Sun, 7=Sat): ");scanf("%d",&w);
        for (i=1;i<w;i++) printf("\t");
        for (i=1;i<=num;i++) {
            printf("%d",i);
            if (!(w%7)) putchar('\n');
            else putchar('\t');
            w++;
        }putchar('\n');
    }
    return 0;
}