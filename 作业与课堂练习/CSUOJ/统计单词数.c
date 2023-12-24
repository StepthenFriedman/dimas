#include <stdio.h>
#include <string.h>
int main() {
    char a[11], b[10000001];
    while (gets(a)&&gets(b)) {
        strcat(a, " ");
        strcat(b, " ");
        int i, s, n = 0, l, j, ss = 0, k, rec;
        for (i=0; a[i]!='\0';i++) if (a[i]>='a') a[i]-='a'-'A';
        for (i=0; b[i]!='\0';i++) if (b[i]>='a') b[i]-='a'-'A';
        for (i=0; b[i]!='\0';i++) if (b[i]==' ') {
            s=1;
            for (j=n, k=0; j<=i, a[k]!='\0';j++,k++) s *= (b[j] == a[k]);
            ss+=(s==1); 
            if (ss == 1&&s == 1) rec = n;  
            n = i;
            n++;
        }
        if (!ss) printf("-1\n");
        else if (ss >= 1) printf("%d %d\n", ss, rec);
    }
    return 0;
}