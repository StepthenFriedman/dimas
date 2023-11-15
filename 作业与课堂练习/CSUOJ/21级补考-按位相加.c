#include <stdio.h>

int main(){
    char s1[100],s2[100],res[100],*opt;
    int len1,len2,maxlen,minlen,remlen,i,j,k;
    while (~scanf("%s%s",&s1,&s2)){
        for (i=0;s1[i]!='\0';i++);len1=i;
        for (i=0;s2[i]!='\0';i++);len2=i;
        maxlen=len2>len1?len2:len1;
        minlen=len2<len1?len2:len1;
        remlen=maxlen-minlen;
        res[minlen]='\0';
        i=len1-1;j=len2-1;k=minlen-1;
        while (1){
            if ((i<0)||(j<0)) break;
            res[k]=s1[i]+s2[j]-48;
            if (res[k]>57) res[k]-=10;
            i--;j--;k--;
        }
        if (len1-len2){
            char *rem=len2>len1?&s2[0]:&s1[0];
            for (i=0;i<remlen;i++) printf("%c",*(rem+i));
        }
        opt=&res[0];
        if (!remlen) {
            while (*opt=='0') opt++;
            if (*opt=='\0') printf("0\n");
            else printf("%s\n",opt);
        }
        else printf("%s\n",opt);
        
    }
    return 0;
}