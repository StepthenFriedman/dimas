#include <stdio.h>
#include <string.h>

void dTB(char *decNum, char *binNum) {
    int n=strlen(decNum),digit,i;
    char remainder[1000];
    while (n) {
        int carry = 0, index = 0;
        for (int i = 0; i < n; ++i) {
            digit=carry*10+decNum[i]-'0';
            if (digit >= 2 || index > 0) remainder[index++]=(digit/2)+'0';
            carry=digit%2;
        }
        binNum[strlen(binNum)]=carry+'0';
        strcpy(decNum, remainder);
        memset(remainder, 0, sizeof(remainder));
        n=strlen(decNum);
    }
}

int main() {
    int i;
    char decNum[1000], binNum[1000*4]={0};
    while (~scanf("%s",decNum)){
        dTB(decNum, binNum);
        for (i=strlen(binNum)-1;i>-1;i--) printf("%c", binNum[i]);
        putchar('\n');
        memset(binNum, 0, sizeof(binNum));
    }
}