#include <stdio.h>

int main(){
    int num;
    while (1) {
        printf("Enter a number between 0 and 32767: ");scanf("%d",&num);
        printf("in octal, your number is: %05o\n",num);
    }
    return 0;
}