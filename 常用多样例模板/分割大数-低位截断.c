#include <stdio.h>
char s[500];int i,digits;
long long int x[100];
int main(){
    while (scanf("%s",&s)!=EOF){
        for (i=0;s[i]!='\0';i++);
        digits=(i/18)+!!(i%18);
        char *p=&s[0];
        for (i=0;i<digits;i++){
            sscanf(p,"%18lld",&x[i]);
            p+=18*sizeof(char);
        }
    }
    return 0;
}