#include <stdio.h>

int main(){
    char ipt[10000],reduce[10000];
    int i,j;
    while(printf("enter a message:"),fgets(ipt,10000,stdin)!=NULL){
        for (i=j=0;ipt[i]!='\0';i++){
            if (ipt[i]>='A'&&ipt[i]<='Z') reduce[j++]=ipt[i];
            else if (ipt[i]>='a'&&ipt[i]<='z') reduce[j++]=ipt[i]+'A'-'a';
        }
        reduce[j]='\0';
        for (i=0;i*2<j;i++) if (reduce[i]!=reduce[j-1-i]) {printf("Not a palindrome\n");goto end;}
        printf("Palindrome\n");
        end:;
    }
}