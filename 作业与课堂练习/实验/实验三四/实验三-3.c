#include <stdio.h>

int main(){
    char ipt[1000];int i,j,tmp,len[1000];char end;
    while (printf("Enter a sentence: "),gets(ipt)){
        printf("Reversal of sentence: ");
        for (i=0;ipt[i]!='\0';i++);
        end=ipt[--i];ipt[i++]=' ';ipt[i--]='\0';
        for (tmp=i;i>-2;i--){
            if (ipt[i]==' '||!~i){
                for (j=i+1;j<=tmp;j++) putchar(ipt[j]);
                tmp=i;
            }
        }printf("\b%c\n",end);
    }
    
    return 0;
}