#include <stdio.h>

int main(){
    int a,b;
    while (1) {
        printf("Enter a two-digit number: ");scanf("%1d%1d",&a,&b);
        printf("You entered the number: ");
        switch (a){
            case 9:printf("ninety-");goto normal;
            case 8:printf("eighty-");goto normal;
            case 7:printf("seventy-");goto normal;
            case 6:printf("sixty-");goto normal;
            case 5:printf("fifty-");goto normal;
            case 4:printf("forty-");goto normal;
            case 3:printf("thirty-");goto normal;
            case 2:printf("twenty-");goto normal;
            case 1:goto teen;
            case 0:goto normal;
        }
        normal:
        switch (b){
            case 9:printf("nine");goto end;
            case 8:printf("eight");goto end;
            case 7:printf("seven");goto end;
            case 6:printf("six");goto end;
            case 5:printf("five");goto end;
            case 4:printf("four");goto end;
            case 3:printf("three");goto end;
            case 2:printf("two");goto end;
            case 1:printf("one");goto end;
        }
        teen:
        switch (b){
            case 9:printf("nineteen");goto end;
            case 8:printf("eighteen");goto end;
            case 7:printf("seventeen");goto end;
            case 6:printf("sixteen");goto end;
            case 5:printf("fifteen");goto end;
            case 4:printf("fourteen");goto end;
            case 3:printf("thirteen");goto end;
            case 2:printf("twelve");goto end;
            case 1:printf("eleven");goto end;
        }
        end: printf(".\n");

    }
    return 0;
}