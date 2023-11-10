#include <stdio.h>
char s[500];int i,digits,last;
long long int x[100];
int main(){
    
    while (scanf("%s",&s)!=EOF&&s[0]!='0'){
        for (i=0;s[i]!='\0';i++);
        digits=(i/15)+!!(i%15);
        char *p=&s[0];char temp[i%15+1];
        snprintf(temp,i%15+1,"%s",s);
        sscanf(temp,"%lld",&x[0]);
        p+=(i%15)*sizeof(char);
        for (i=1;i<digits;i++){
            sscanf(p,"%15lld",&x[i]);
            p+=15*sizeof(char);
        }
        for (i=0;i<digits-1;i++){
            x[i+1]+=(x[i]%17)*1000000000000000;
        }
        printf("%d\n",!(x[digits-1]%17));
    }
    return 0;
}

