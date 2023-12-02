#include<stdio.h>
#include<string.h>

int main(){
    char arr[100000],bef[100000];
    while(gets(arr)!=NULL){
    gets(bef);
    char *p=strstr(arr,bef);
    if(p==NULL)printf("No!\n");
    else printf("Yes!\n");
    }
    return 0;
}