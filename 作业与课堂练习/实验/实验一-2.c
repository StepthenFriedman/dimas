#include <stdio.h>

int main(){
    double loan,rate,pay;
    while (1) {
        printf("Enter amount of loan: ");scanf("%lf",&loan);
        printf("Enter interest rate: ");scanf("%lf",&rate);
        printf("Enter monthly payment: ");scanf("%lf",&pay);
        printf("Balance remaining after first payment: $%.2f\n",loan+=((loan*rate/1200.)-pay));
        printf("Balance remaining after second payment: $%.2f\n",loan+=((loan*rate/1200.)-pay));
        printf("Balance remaining after third payment: $%.2f\n",loan+=((loan*rate/1200.)-pay));
    }
    return 0;
}