#include<stdio.h>
#include<string.h>

char list[110][22];

int main(){
	char c,name[22];
    int i=0,j;
    while(scanf("%s",&list[i++])!=EOF){
		if(scanf("%c",&c)==EOF||c=='\n'){
			while(gets(name)!=NULL&&name[0]!='\0'){
		        for (j=0;j<i;j++) if (!strcmp(list[j],name)) {
                    printf("yes\n");goto next;
                }
                printf("no\n");
                next:;
	        }
			i=0;
		}
	}
    return 0;
}

