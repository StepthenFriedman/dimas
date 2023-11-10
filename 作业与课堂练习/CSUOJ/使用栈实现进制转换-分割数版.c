#include <stdio.h>
char s[300];int i,j,digits,last,next;
long long int x[100];
int res[500];
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
        next=1;j=0;
        while (next){
            next=0;
            for (i=0;i<digits-1;i++) if (x[i]){
                if (x[i]%2) x[i+1]+=1000000000000000000;
                x[i]/=2;next=1;
            }
            if (x[digits-1]) next=1;
            res[j++]=x[digits-1]%2;
            x[digits-1]/=2;
        }
        i=j-1;
        while (!res[i]) i--;
        for (;i>-1;i--) printf("%d",res[i]);
        putchar('\n');
        
    }
    return 0;
}
