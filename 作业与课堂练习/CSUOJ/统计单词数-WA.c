#include<stdio.h>
#include<string.h>

char ipt[100];

char word[20];

int cmp(char a,char b){
    return (a==b)||((a+'A'-'a')==b)||((a+'a'-'A')==b);
}

int main(){
    int i,count,first,sum,len1,len2;
    while (~scanf("%s",&word)){
        printf("%s\n",word);
        len1=strlen(word);
        count=0,first=-1,sum=0;
        getchar();
        next:scanf("%s",&ipt);
        printf("%s ",ipt);
        len2=strlen(ipt);
        if (len1!=len2) goto end;
        for (i=0;i<len1;i++) if (!cmp(word[i],ipt[i])) goto end;
        sum++;
        if (first==-1) first=count;
        end:
        count+=len2+1;
        if (getchar()==' ') goto next;

        if (sum) printf("%d %d\n",sum,first);
        else printf("-1\n");

    }
    return 0;
}