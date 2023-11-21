#include <stdio.h>

int isPal(char* a, char* b, int n){
    for (int i=0;i<n;i++) if (a[i]!=b[n-i-1]) return 0;
    return 1;
}

int main(){
    int n,m,i,j,max,sp;
    char ipt[200][60];
    char res[10000];
    char selfPal[60];
    while (sp=max=0,~scanf("%d%d",&n,&m)){
        for (i=j=0;i<n;i++) scanf("%s",&ipt[i]);
        for (char *p=&ipt[0];p<&ipt[n];p+=60){
            for (char *p2=p;p2<&ipt[n];p2+=60){
                if (isPal(p,p2,m)){
                    if (p!=p2) {
                        for (i=0;i<m;i++) res[j++]=p[i];max++;
                    }
                    else {
                        sp=1;for (i=0;i<=m;i++) selfPal[i]=p[i];
                    }
                }
            }
        }
        res[j]='\0';
        printf("%d\n",max*m*2+sp*m);
        printf("%s",res);
        if (sp) printf("%s",selfPal);
        for (i=j-1;i>-1;i--) putchar(res[i]);
        putchar('\n');
    }
    return 0;
}