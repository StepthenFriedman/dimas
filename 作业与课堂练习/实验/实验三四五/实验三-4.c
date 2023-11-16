#include <stdio.h>

int main(){
    char ipt[100];int i,j,shift;
    while (printf("Enter message to be encrypted: "),gets(ipt)){
        printf("Enter shift amount (1~25): ");scanf("%d",&shift);
        for (i=0;ipt[i]!='\0';i++){
            if (ipt[i]>=65&&ipt[i]<=90) {
                ipt[i]+=shift;if (ipt[i]>90) ipt[i]-=26;
            }
            else if (ipt[i]>=97&&ipt[i]<=122) {
                ipt[i]+=shift;if (ipt[i]>122) ipt[i]-=26;
            }
        }
        printf("Encrypted message: %s\n",ipt);
    }
    
    return 0;
}