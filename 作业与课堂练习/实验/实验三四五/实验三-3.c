#include <stdio.h>
#include <string.h>

int main(){
    char ipt[1000];int i;
    while (printf("Enter a sentence: "),gets(ipt)){
        printf("Reversal of sentence: ");
        for (i=0;ipt[i]!='\0';i++);
        for (;i>-1;i--) putchar(ipt[i]);
        putchar('\n');
    }  
    return 0;
}