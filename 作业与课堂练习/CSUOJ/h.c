#include <stdio.h>
#include <string.h>

int isBig(char x){
    return x>='A'&&x<='Z';
}
int isSmall(char x){
    return x>='a'&&x<='z';
}

int isNum(char x){
    return x>='0'&&x<='9';
}

typedef struct element{
    char name[3];
    int unknown;
}ele;

char ipt[1000];
ele list[1000];
int main(){
    int i,j,eleNum,tempNum,eleHandle,multiply;
    char tempName[3];
    while (~scanf("%s",&ipt)){
        eleNum=0;tempNum=1;multiply=1;tempName[0]='\0';
        for (i=0;ipt[i]!='=';i++){
            if (isBig(ipt[i])) tempName[0]=ipt[i],tempName[1]='\0';
            else if (isSmall(ipt[i])) tempName[1]=ipt[i],tempName[2]='\0';
            else if (ipt[i]=='+') multiply=1;
            else if (isNum(ipt[i])) {
                if (i==0||ipt[i-1]=='+') multiply=ipt[i]-'0';
                else tempNum=ipt[i]-'0';
            }

            if (((isBig(ipt[i+1]))||ipt[i+1]=='+'||ipt[i+1]=='=')&&tempName[0]!='\0'){
                eleHandle=0;
                for (j=0;j<eleNum;j++) if (!strcmp(tempName,list[j].name)){
                    eleHandle=j;goto next1;
                }
                strcpy(list[eleNum].name,tempName);
                list[eleNum].unknown=0;
                eleHandle=eleNum++;

                next1:
                list[eleHandle].unknown+=tempNum*multiply;

                tempName[0]='\0';
                tempNum=1;
            }
        }
        for (int x=0;x<eleNum;x++)printf("%s: %d\n",list[x].name,list[x].unknown);
        multiply=1;tempNum=1;tempName[0]='\0';
        for (i++;ipt[i]!='\0';i++){
            if (isBig(ipt[i])) tempName[0]=ipt[i],tempName[1]='\0';
            else if (isSmall(ipt[i])) tempName[1]=ipt[i],tempName[2]='\0';
            else if (ipt[i]=='+') multiply=1;
            else if (isNum(ipt[i])) {
                if (ipt[i-1]=='='||ipt[i-1]=='+') multiply=ipt[i]-'0';
                else tempNum=ipt[i]-'0';
            }

            if ((isBig(ipt[i+1])||ipt[i+1]=='+'||ipt[i+1]=='\0')&&tempName[0]!='\0'){
                //printf("i:%d get element:%s %d*%d\n",i,tempName,tempNum,multiply);
                eleHandle=0;
                for (j=0;j<eleNum;j++) if (!strcmp(tempName,list[j].name)){
                    eleHandle=j;goto next2;
                }
                printf("No\n");
                goto end;
                next2:
                list[eleHandle].unknown-=tempNum*multiply;
                tempName[0]='\0';
                tempNum=1;
            }
        }


        for (int x=0;x<eleNum;x++)printf("%s: %d\n",list[x].name,list[x].unknown);
        for (i=0;i<eleNum;i++) if (list[i].unknown) {
            printf("No\n");goto end;
        }

        printf("Yes\n");
        end:;
    }
    return 0;
}