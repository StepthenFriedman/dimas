#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef unsigned long long ULL;

ULL f[1005 * 1005];

int peroid(ULL n)
{
    f[0] = 0, f[1] = 1;
    for (int i = 2; i < 1005 * 3; i++)
    {
        if (i >= 2) f[i] = (f[i - 2] + f[i - 1]) % n;
        if (f[i - 1] == 0 && f[i] == 1)
        {
            int p = i - 1;
            return p;
        }
    }
}

ULL qmod(ULL a, ULL b, int mod)//快速幂
{
    a = (a % mod + mod) % mod;
    ULL r = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            r = r * a % mod;
        }
        else a = (a * a) % mod;
        b /= 2;
    }
    return r;
}

int main()
{
    ULL a, b, c;
    ULL tmp;
    int n;
    while (scanf("%llu%llu%d", &a, &b, &n) != EOF)
    {
        if (a == 0)
        {
            printf("0\n");
            continue;
        }
        if (n == 1)
        {
            printf("0\n");
            continue;
        }
        else
        {
            int q = peroid(n);
            int p = qmod(a, b, q);
            printf("%llu\n", f[p]);
        }
    }
    return 0;
}
