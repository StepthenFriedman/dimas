#include <stdio.h>

int main(){
    char ipt[1000],*p,num[10],opera;int i,j,tmp,len[500];float x,y;
    while ((printf("Enter an expression: "),~scanf("%s",&ipt))){
        for (tmp=-1,i=j=0;ipt[i]!='\0';i++){
            if (ipt[i]=='+'||ipt[i]=='-'||ipt[i]=='*'||ipt[i]=='/') {
                len[j++]=i-tmp;tmp=i;
            }
        }
        p=&ipt[0];
        snprintf(num,len[0],"%s",p);
        p+=len[0]-1;
        sscanf(num,"%f",&x);
        for (i=1;i<=j;i++) {
            opera=*p;p++;
            snprintf(num,len[i],"%s",p);
            p+=len[i]-1;
            sscanf(num,"%f",&y);
            switch (opera){
            case '+':x+=y;continue;
            case '-':x-=y;continue;
            case '*':x*=y;continue;
            case '/':x/=y;continue;
            }
        }
        printf("Value of the expression: %g\n",x);
    }
    
    return 0;
}