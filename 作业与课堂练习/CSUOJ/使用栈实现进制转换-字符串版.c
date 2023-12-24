#include <stdio.h>
char s[500];int res[500];
int i,j,digits,next;
int main(){
    while (scanf("%s",&s)!=EOF){
        for (i=0;s[i]!='\0';s[i++]-=48);

        digits=i;
        j=0;next=1;
        while (next){
            next=0;
            for (i=0;i<digits-1;i++) if (s[i]) {
                if (s[i]%2) s[i+1]+=10;
                s[i]/=2;next=1;
            }
            if (s[digits-1]) next=1;
            res[j++]=s[digits-1]%2;
            s[digits-1]/=2;
        }
        j--;
        while (!res[j]) j--;
        for (i=j;i>-1;i--) printf("%d",res[i]);
        putchar('\n');
    }
    return 0;
}