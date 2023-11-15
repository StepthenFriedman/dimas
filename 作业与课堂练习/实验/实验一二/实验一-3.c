#include <stdio.h>

int main(){
    int num;double price;char mdy[20];
    while (1) {
        printf("Enter item number: ");scanf("%d",&num);
        printf("Enter unit price: ");scanf("%lf",&price);
        printf("Enter purchase date (mm/dd/yyyy): ");scanf("%s",&mdy);
        printf("\nItem\tUnit\tPurchase\n\tPrice\tDate\n%d\t$%-4.2f\t%s\n",num,price,mdy);
    }
    return 0;
}