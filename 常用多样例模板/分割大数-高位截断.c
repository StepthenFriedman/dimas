#include <stdio.h>
char s[500];int i,digits,last;
long long int x[100];
int main(){
    
    while (scanf("%s",&s)!=EOF){
        for (i=0;s[i]!='\0';i++);
        digits=(i/18)+!!(i%18);
        char *p=&s[0];char temp[i%18+1];
        snprintf(temp,i%18+1,"%s",s);
        sscanf(temp,"%lld",&x[0]);
        p+=(i%18)*sizeof(char);
        for (i=1;i<digits;i++){
            sscanf(p,"%18lld",&x[i]);
            p+=18*sizeof(char);
        }
        for (i=0;i<digits;i++) printf("%lld ",x[i]);
        
    }
    return 0;
}

unsigned long long* getnum(){
    char s[1000];int i,digits,last;
    unsigned long long *x=(unsigned long long *)malloc(100*sizeof(unsigned long long));
    scanf("%s",&s);
    for (i=0;s[i]!='\0';i++);
    digits=(i/18)+!!(i%18);
    char *p=&s[0];char temp[i%18+1];
    snprintf(temp,i%18+1,"%s",s);
    sscanf(temp,"%llu",&x[0]);
    p+=(i%18)*sizeof(char);
    for (i=1;i<digits;i++){
        sscanf(p,"%18llu",&x[i]);
        p+=18*sizeof(char);
    }
    for (i=0;i<digits;i++) printf("%llu ",x[i]);
    return x;
}