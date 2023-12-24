#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void dsjjf(char* a, char* b, int jjf)//使用特别注意改a1,b1长度，(a-b)格式，1代表加法，0代表减法
{

    int af = 0, bf = 0, f = 0;
    if (a[0] == '-') { af = 1; }
    if (b[0] == '-') { bf = 1; }
    int lena = strlen(a); int lenb = strlen(b);
    int len = (lena - af > lenb - bf) ? lena - af : lenb - bf;
    char a1[1000]; memset(a1, 0, sizeof(a1));
    char b1[1000]; memset(b1, 0, sizeof(b1));
    for (int i = lena - 1, j = 0; i >= 0; i--, j++)
    {
        a1[j] = a[i]; if (i == af) { break; }
    }lena -= af;// printf("%s %d\n", a1, lena);
    for (int i = lenb - 1, j = 0; i >= 0; i--, j++)
    {
        b1[j] = b[i]; if (i == bf) { break; }
    }lenb -= bf; //printf("%s %d\n", b1, lenb);
    if (jjf == 0) { if (bf == 0) { bf = 1; } else { bf = 0; } }
    if (af == bf)
    {
        f = af;
        for (int i = 0; i < len; i++)
        {
            int c, d;
            if (a1[i] == 0) { c = 0; }
            else { c = a1[i] - '0'; }
            if (b1[i] == 0) { d = 0; }
            else { d = b1[i] - '0'; }
            int he = c + d; //printf("a%d %c /\n", he, a1[i]);
            if (he >= 10) { if (a1[i + 1] > 0) { a1[i + 1]++; } else { a1[i + 1] = '1'; } }
            a1[i] = he % 10 + '0'; //printf("b%d %c /\n", he, a1[i]);
        }
    }
    if (af != bf)
    {
        char* a2 = a1; char* b2 = b1; int lena2 = lena; int lenb2 = lenb;
        if (lena > lenb) { f = af; }
        if (lena < lenb) { f = bf; char* tm = a2; a2 = b2; b2 = tm; lena2 = lenb; lenb2 = lena; }
        if (lena == lenb)
        {
            for (int i = lena; i >= 0; i--)
            {
                if (a1[i] > b1[i]) { f = af; break; }
                if (a1[i] < b1[i]) { f = bf; char* tm = a2; a2 = b2; b2 = tm; lena2 = lenb; lenb2 = lena; break; }
            }
        }
        // printf("f值%d %s %s %d\n", f,a2,b2,lena2);
        int bit = 0;
        for (int i = 0; i < lena2; i++)
        {
            int tma = (a2[i] > 0) ? a2[i] - '0' : 0;
            int tmb = (b2[i] > 0) ? b2[i] - '0' : 0;
            if (tma - bit >= tmb)
            {
                a1[i] = tma - tmb - bit + '0'; bit = 0;
            }
            else {
                a1[i] = tma + 10 - tmb - bit + '0'; bit = 1;
            }
            // printf("%d %d %css\n", tma, tmb,a1[i]);
        }
        for (int i = lena2 - 1; i >= 0; i--)
        {
            if (i == 0) { a1[1] = 0; len = 1; break; }
            if (a1[i] != '0') { break; }
            if (a1[i] == '0' && a1[i - 1] != '0') { a1[i] = 0; len = i; break; }
        }
    }
    // printf("\n%s\n",a1);
    if (f == 1) { a[0] = '-'; }if (af == bf) { len = strlen(a1); }
    a[len + f] = 0;
    for (int i = len - 1 + f, j = 0; i >= f; i--, j++)
    {
        a[i] = a1[j]; //printf("%c %d\n", a[i], i);
    };
}
void ssb(int* a, int b,int* len)//a是素数表，b是算0到b的素数，len是定义的数组长度,传出数组实际长度
{
    for (int i = 0; i < *(len); i++)
    {
        a[i] = 0;
    }
    a[0] = 2; a[1] = 3; int f = 2;
    for (int i = 4; i <= b; i++)
    {
        if (f >= *(len)) { break; }
        int g = sqrt(i);
        for (int j = 0; j <= i; j++)
        {
            if (a[j] == 0) { break; }
            if (i % a[j] == 0) { break; }
            if (i % a[j] != 0 && a[j + 1] > g) { a[f] = i; f++; break; }
        }
    }
    *(len) = f;
}
void jzcf(long long m,long long n,long long p,int sfqm,long long mc,long long*jg,long long mod)//特别注意如果数组不够大，移动到全局变量区域声明，求矩阵幂填1，不求填0,整数求幂填2，传入一个指针保存结果，若不要取模，输入0,矩阵相乘m、n是a的行数列数，n、p是b的，矩阵求幂仅填对m即可，注意填幂次，整数求幂填m为被乘数，mc为次数，结果存在jg中
{
    if (mod == 0) { mod = 9223372036854775807; }
    long long a[100][100]; long long b[100][100]; long long c[100][100]; memset(c, 0, sizeof(c));
    //如果不够大，移动到全局变量区域声明
    if (sfqm == 2)
    {
        *(jg) = 1;
        while (mc > 0)
        {
            if (mc % 2 == 1)
              {
                  *(jg) =( * (jg)*m)%mod;
               }
               m =( m * m)%mod;
               mc/= 2;
        }
    }
    if (sfqm == 1 || sfqm == 0)
    {
        for (long long i = 0; i < m; i++)
        {
            for (long long j = 0; j < n; j++)
            {
                scanf("%lld", &a[i][j]);
                //printf("%d ", a[i][j]);
            }//printf("\n");
        }
    }
    if (sfqm == 1)
    {
        long long d = mc; p = m; n = m;
        memset(c, 1, sizeof(c));
        for (long long i = 0; i < m; i++)
        {
            for (long long j = 0; j < n; j++)
            {
                c[i][i] = 1; if (i != j) { c[i][j] = 0; }
            }
        }
        
        while (d>0)
        {
            memset(b, 0, sizeof(b)); 
            if (d %2==1)
            {
                //printf("jin%d %d %d\n",m,n,p);
                for (long long k = 0; k < m; k++)
                {
                    for (long long i = 0; i< p; i++)
                    {
                        for (long long j = 0; j < n; j++)
                        {
                            //printf("%d %d %d\n", a[i][k], b[k][j], c[i][j]);
                            b[i][j] = (b[i][j] + c[i][k] * a[k][j]) %mod; //printf("%d %d %d\n", a[i][k],b[k][j], c[i][j]);
                        }
                    }//printf("mm\n");
                }

                for (long long i = 0; i < m; i++)
                {
                    for (long long j = 0; j < n; j++)
                    {
                        c[i][j] = b[i][j];// printf("啊%d\n", b[i][j]);
                    }//printf("\n");
                }
            }
            memset(b, 0, sizeof(b));
            for (long long i = 0; i < m; i++)
            {
                for (long long j = 0; j < p; j++)
                {
                    for (long long k = 0; k < n; k++)
                    {
                        b[i][j] = (b[i][j]+a[i][k] * a[k][j]) %mod;
                    }
                }//printf("\n");
            }

            for (long long i = 0; i < m; i++)
            {
                for (long long j = 0; j < n; j++)
                {
                    a[i][j] = b[i][j];  //printf("吧%d\n", a[i][j]);
                }
            }
            d/=2;
           
        }
    }
    if (sfqm == 0)
    {
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < p; j++)
            {
                scanf("%lld", &b[i][j]);
                //printf("%d ", b[i][j]);
            }
        }
        for (long long i = 0; i < m; i++)
        {
            for (long long j = 0; j < p; j++)
            {
                for (long long k = 0; k < n; k++)
                {
                    c[i][j] += (a[i][k] * b[k][j]) % mod; //printf("%d %d %d\n", a[i][k],b[k][j], c[i][j]);
                }
            }//printf("\n");
        }
    }
    if (sfqm == 0 || sfqm == 1) 
    {
        for (long long i = 0; i < m; i++)
        {
            for (long long j = 0; j < p; j++)
            {
                printf("%lld ", c[i][j]);
            }printf("\n");
        }
    }
}
struct sr { int a; };//把所有数据放在这里，以兼容wnlb函数(支持字符串成员）
int bjsr(struct sr* a, struct sr* b)//这是一个重要的比较函数，可以用于查找指定元素（ms5），需要使用这些功能时应该调整，如果不用，只要使这个函数有返回值即可
{
    if ((*(a)).a == (*(b)).a) {
        return 0;
    }
    else 
    { return 1; }
}
struct lb { struct sr sj; struct lb* next; };//最好不要改动.如果需要空表提示，进入248行修改
void wnlb(struct lb** tou1,struct lb** wei1,struct lb**qjd1,struct lb** jd,int ms,int* fhz)
//要求tou1、wei1、qjd1为链表指针，jd为链表指针（malloc申请lb空间），fhz为某些模式传入值、返回值变量，均传地址。ms0头插链接单链表节点，ms1尾插链接单链表节点，ms2反转链表，ms3清空链表，
// ms4计算链表元素个数，结果存在fhz中，ms5查找指定元素，要求提前将此元素存在jd中，从qjd1所在位开始搜索（需要在开始时令其为tou1），返回为指定值的jd的next到qjd1
//（可直接传入wnlb从此处继续搜索相同元素），返回fhz表示此元素位置，没有回0,注意如果想让函数自己算出每一个相同元素所在的位置，在搜索工作循环里不能修改fhz的值，它被用于记录每一次搜索完时该元素的位置
// ms6查找指定位的元素，指定位存在fhz中，求中间节点fhz为0，求倒数节点fhz为负数，返回找到的元素的sj存在jd中，返回值所在的位数存在fhz中，若没有，fhz返回0,不传回jd，千万注意储存jd初始值以免程序挂掉！！！
//ms7在指定节点（从1开始）后插入元素，头插输入0，节点存在jd里，插入失败返回0于fhz，指定位存在fhz里,ms8删除指定位置节点,指定位存在fhz里,删除失败返回0于fhz
{
    struct lb* tou = *(tou1); struct lb* wei = *(wei1);  if (ms!=0&&ms != 1 && tou == NULL) { return; }
    if (ms == 1||ms==0) 
    {
        struct lb* qjd = *(qjd1);
        struct lb* zjd = (struct lb*)malloc(sizeof(struct lb)); zjd->sj = (*(jd))->sj;// printf("%d %p\n", zjd->sj.a,zjd);
        if (tou != NULL && qjd != NULL && ms == 0) { zjd->next = tou; tou = zjd; }
        if (tou != NULL && qjd != NULL && ms == 1) { qjd->next = zjd; zjd->next = wei; qjd = zjd; }
        if (tou == NULL) { tou = zjd;  zjd->next = wei; qjd = zjd;}
        *(tou1) = tou; *(wei1)= wei; *(qjd1) = qjd; return;
    }
    if (ms == 2)//(反转单链表)
    {
        if (tou != NULL)
        {
            struct lb* h2 = NULL; struct lb* h1 = tou; struct lb* h3 = NULL;
            while (h1)
            {
                if (h1->next == wei) { wei = h1; }
                //printf("e%d %d\n", h1, h1->sj.a);
                h3 = h1->next; h1->next = h2; h2 = h1;  //h1 = h3; //if (h1->next == wei) { printf("jin"); wei = h1; }
                if (h1 != NULL)
                {
                    //printf("e=p=%d %d\n", h1->sj.a, h1->next);
                } h1 = h3;
            }tou->next = h1;
            *(tou1) = wei; *(wei1) = h1;
        }return;
    }
    if (ms == 3)//删除链表
    {
        struct lb* bl = tou; struct lb* b2 = tou;
        if (tou == NULL) { printf("kongde" ); return; }
        while (bl != wei)
        {
            b2 = bl; bl = bl->next; b2->next = bl; free(b2);
        } *(tou1) = NULL; *(wei1) = NULL; return;
    }
    if (ms == 4||ms==5||ms==6)
    {
        int a = 0; struct lb* k = tou; if (ms == 5) { k = *(qjd1); }
        for (struct lb* i = k; i != wei; i = i->next)
        {
            if (ms == 5) 
            {
                if (bjsr(&(i->sj), &(*(jd))->sj) == 0)
                {
                    int b; if (k == tou) { b = 0; }else { b = *(fhz); }
                    a++; *(fhz) = a + b; *(qjd1) = i->next;return;
                }
            }
            if (ms == 6)//0时k是快指针，一次跳两格（k从指1到3，3到5）若总元素数为单数，k最后指向最后一个元素，i走到中间的前一个元素，让i再走一步返回，若为偶数，指向wei,i刚好走一半，可直接返回
                //负数时因为a最后加1，实际应该在2时慢指针k才启动，k要比i少走倒数的步数，所以fhz+a=-1时在1的位置，传回fhz时应该加2
            {
                if (*(fhz) == 0 && k->next == wei) { (* (jd))->sj = i->sj; *(fhz) = a + 1;  return; }
                if (*(fhz) == 0 && k!=wei && k->next!=wei){k = k->next->next;}
                if (*(fhz) == 0 && k == wei) { (*(jd))->sj = i->sj; *(fhz) = a+1;  return; }
                if (*(fhz) > 0) { if (a == *(fhz)-1) { (*(jd))->sj = i->sj; return; } }
                if (*(fhz) < 0 && *(fhz)+a >= 0) { k = k->next; }
                if (*(fhz) < 0 && i->next == wei && *(fhz)+a >= -1) { (*(jd))->sj = k->sj; *(fhz) = a + *(fhz)+2; return; }
            }
            a++;
        }if (ms == 5||ms==6) { a = 0; }*(fhz) = a; return;
    }
    if (ms == 7||ms==8)
    {
        struct lb* a = (struct lb*)malloc(sizeof(struct lb)); int b=0;
        if (ms == 7) { a->sj = (*(jd))->sj; a->next = NULL; } struct lb* c = tou;
        if (*(fhz) == 0&&ms==7)
        {
            a->next = tou; tou = a; *(tou1) = tou; return;
        }
        if (*(fhz) == 1 && ms == 8)
        {
            tou = c->next; free(c); *(tou1) = tou; return;
        }
        for (struct lb* i = tou; i != wei; i = i->next)
        {
            b++;
            if (b == *(fhz)&&ms==7)
            {
                c = i->next; i->next = a; a->next = c; return;
            }
            if (b == *(fhz)-1 && ms == 8){c = i;}
            if (b == *(fhz) && ms == 8)
            {
                c->next = i->next; free(i); return;
            }
        }*(fhz) = 0;
    }
}
void dscf(char* a, int len, int cs, char* ys, int* kyws, int sfzzzh)
{
    int ys1 = 0; if (cs == 0) { return; }
    for (int i = 0; i < len; i++)
    {
        int bcs = a[i] - '0' + 10 * ys1;
        a[i] = bcs / cs + '0';
        ys1 = bcs % cs;
        if (ys1 < 0 && sfzzzh == 1 && cs < 0) { ys1 -= cs; char cmp[3] = "1"; dsjjf(a, cmp, 1); }
    }

    if (ys1 < 10) { ys[*(kyws)] = ys1 + '0'; }
    else { ys[*(kyws)] = ys1 - 10 + 'A'; }
    (*(kyws))++;

}
int main()
{
    //正常多样例输入使用wnlb函数
    int fhz;int b=1;
    struct lb* k = NULL; struct lb* l = NULL; struct lb* m=(struct lb*)malloc(sizeof(struct lb)); struct lb* qjd = NULL;
    while (scanf("%d", &m->sj.a) != EOF)
    {
        //memset(m->sj.b, 0, sizeof(m->sj.b)); m->sj.b[0] = m->sj.a; m->sj.b[1] = m->sj.a;
        wnlb(&k, &l, &qjd, &m,0 ,&fhz); //printf("a%ca\n",jc);
        if (getchar() == '\n')
        {b++;
            //wnlb(&k, &l, &qjd, &m,2,&fhz);
            for (struct lb* i = k; i!=l; i = i->next)
            {
                printf("%d ", i->sj.a);
            }printf("\n"); m->sj.a = 2; fhz = 4;
             wnlb(&k, &l, &qjd, &m, 3, &fhz);
        }
    }//以下是不正常输入时的使用示例
    for (struct lb* i = k; i!=l; i = i->next)
            {
                printf("%d ", i->sj.a);
            }printf("\n");
    return 0;
}