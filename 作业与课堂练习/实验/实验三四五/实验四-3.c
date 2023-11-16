#include <stdio.h>

int main(){
    char ipt;int res,stack[1000],i;
    while (1){
        printf("Enter an RPN expression: ");i=0;
        while (1){
            scanf("%c",&ipt);
            switch (ipt){
                case '=': goto end;
                case ' ': case '\n': continue;
                case '+': stack[(--i)-1]+=stack[i]; continue;
                case '-': stack[(--i)-1]-=stack[i]; continue;
                case '*': stack[(--i)-1]*=stack[i]; continue;
                case '/': stack[(--i)-1]/=stack[i]; continue;
                case 48 ... 57: stack[i++]=ipt-48; continue;
                default:return 0;
            }
        }
        end:printf("Value of expression: %d\n",stack[i-1]);
    }
    return 0;
}