#include <stdio.h>

int main(){
    char ipt[1010]; int i,num7,sum;
    while (~scanf("%s",&ipt)){
        sum=num7=0;
        for (i=0;ipt[i]!='\0';i++){
            sum+=ipt[i]-'0';
            if (ipt[i]=='7') num7++;
        }
        if ((sum%7==0)||num7*2>i) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}