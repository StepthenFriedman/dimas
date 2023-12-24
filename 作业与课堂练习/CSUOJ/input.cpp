#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string.h>

int main(){
    char* ipt=(char*)malloc(1000000*sizeof(char)),*name=(char*)malloc(100*sizeof(char)), *cmd=ipt;
    printf(">>input file:");
    scanf("%s",name);
    printf(">>input samples here:\n");
    ipt[0]='e',ipt[1]='c',ipt[2]='h',ipt[3]='o',ipt[4]=' ',ipt[5]='"',ipt+=6;
    while (scanf("%s",ipt)!=EOF) {
        for (;*ipt!='\0';ipt++);
        *ipt='\n';ipt++;
    }
    *ipt='\0';
    strcat(ipt,"\" | ");
    strcat(ipt,name);
    printf(">>your output:\n");
    clock_t start = std::clock();
    int returnCode = system(cmd);
    clock_t end = std::clock();
    printf(">>program ends\n  total time: %ld ms\n  return value: %d\n",end-start,returnCode);
    free(cmd);
    free(name);
	return returnCode;
}