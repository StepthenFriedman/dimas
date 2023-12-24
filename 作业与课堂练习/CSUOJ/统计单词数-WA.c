#include<stdio.h>

char ipt0[1000005];

char word[20];

int cmp(char a,char b){
    return (a==b)||((a+'A'-'a')==b)||((a+'a'-'A')==b);
}

int main(){
    ipt0[0]=' ';
    char *ptr,*ipt=&ipt0[1];
    int i,j,count,first,sum,len1,len2;
    while (~scanf("%s",&word)){
        for (len1=0;word[len1]!='\0';len1++);
        count=first=-1,sum=0;
        getchar();
        gets(ipt);
        if (ipt0[1]=='\0') goto end;
        for (i=0;ipt0[i]!='\0';i++){
            if (ipt0[i]==' '){
                i++;count++;
                for (len2=0;ipt0[i+len2]!='\0'&&ipt0[i+len2]!=' ';len2++);
                if (len1!=len2) goto next;
                for (j=0;j<len1;j++){
                    if (!cmp(word[j],ipt0[i+j])) goto next;
                }
                if (first==-1) first=count;
                sum++;
            }
            next:;
        }
        if (~first) printf("%d %d\n",sum,first);
        else end:printf("-1\n");
    }
    return 0;
}