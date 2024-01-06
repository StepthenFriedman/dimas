#include <stdio.h>
int main(){
    int i;
    char ipt1[5000],ipt2[5000];
    while (~scanf("%s%s",ipt1,ipt2)){
        for (i=0;ipt1[i]!='\0'&&ipt2[i]!='\0';i++) putchar(((ipt1[i]-'a')+(ipt2[i]-'a'))%26+'a');
        if (ipt2[i]=='\0') for (;ipt1[i]!='\0';i++) putchar(ipt1[i]);
        else if (ipt1[i]=='\0') for (;ipt2[i]!='\0';i++) putchar(ipt2[i]);
        putchar('\n');
    }
    return 0;
}