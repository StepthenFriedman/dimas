#include <stdio.h>
#include <string.h>
 
int zhishu(int a) {
	if (a < 2)
		return 0;
	else if (a == 2)
		return 1;
	else {
		for (int i = 2; i < a; i++) {
			if (a % i == 0)
				return 0;
		}
	}
	return 1;
}
 
int panduan2(int a) {
	int sum = 0;
	while (a > 0) {
		sum = sum + a % 10;
		a /= 10;
	}
	if (zhishu(sum))
		return 1;
	else
		return 0;
}
 
int panduan3(int a) {
	while (a > 0) {
		int t = a % 10;
		a /= 10;
		if (zhishu(t) )
			return 1;
	}
	return 0;
}
 
int main() {
	char sen[10086];
	int m;
	while (scanf("%s %d", sen, &m) != EOF) {
		int length = strlen(sen);
		int num = length / m + 1;
		int ass[num + 5];
		int way = 0;
		int temp = 0;
		int r = 0;
		for (int i = 0; sen[i] != 0; i++) {
			if (way < m) {
				temp = temp * 10 + sen[i] - '0';
				way++;
			} else {
				i--;
				ass[r++] = temp;
				temp = 0;
				way = 0;
			}
		}
		if (way != 0) {
			ass[r++] = temp;
 
		}
		int ans1[r], ans2[r], ans3[r], ans4[r];
		int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
		for (int i = 0; i < r; i++) {
			if ((zhishu(ass[i]))) {
				ans1[r1++] = ass[i];
			} else if (panduan2(ass[i])) {
				ans2[r2++] = ass[i];
			} else if (panduan3(ass[i])) {
				ans3[r3++] = ass[i];
			} else {
				ans4[r4++] = ass[i];
			}
		}
		int k = 3;
		int ling = 0;
		int max = r1 > r2 ? r1 : r2;
		max = max > r3 ? max : r3;
		max = max > r4 ? max : r4;
		for (k = 3; k <= 101; k++) {
			if (k % 2 == 0)
				continue;
			int all = k * k, left = all - k - k + 1;
			ling = left - r1 - r2 - r3 - r4;
			left /= 4;
			if (left >= max)
				break;
 
		}
		int ar1 = 0, ar2 = 0, ar3 = 0, ar4 = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (j == i || j == k - i - 1)
					printf("    *");
				else {
					if (i < (k / 2)) {
						if (j < i) {
							if (ar2 < r2)
								printf("%5d", ans2[ar2++]);
							else
								printf("    0");
						} else if (j > k - i - 1) {
							if (ar3 < r3)
								printf("%5d", ans3[ar3++]);
							else
								printf("    0");
						} else if (ar1 < r1)
							printf("%5d", ans1[ar1++]);
						else
							printf("    0");
					} else {
						if (j < k - i - 1) {
							if (ar2 < r2)
								printf("%5d", ans2[ar2++]);
							else
								printf("    0");
						} else if (j > i) {
							if (ar3 < r3)
								printf("%5d", ans3[ar3++]);
							else
								printf("    0");
						} else if (ar4 < r4)
							printf("%5d", ans4[ar4++]);
						else
							printf("    0");
					}
				}
 
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}