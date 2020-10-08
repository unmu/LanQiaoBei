问题描述
　　在一个奇怪的星球上驻扎着两个虫群A和B，它们用奇怪的方式繁殖着，在t+1时刻A虫群的数量等于t时刻A虫群和B虫群数量之和，t+1时刻B虫群的数量等于t时刻A虫群的数量。由于星际空间的时间维度很广阔，所以t可能很大。OverMind 想知道在t时刻A虫群的数量对 p = 1,000,000,007.取余数的结果。当t=1时 A种群和B种群的数量均为1。
输入格式
　　测试数据包含一个整数t，代表繁殖的时间。
输出格式
　　输出一行，包含一个整数，表示对p取余数的结果
样例输入
10
样例输出
89
样例输入
65536
样例输出
462302286
数据规模和约定
　　对于50%的数据 t<=10^9
　　对于70%的数据 t<=10^15
　　对于100%的数据 t<=10^18

-----------------------------------------------
#include<bits/stdc++.h>
using namespace std;

void mulm(long long a[2][2], long long b[2][2], long long r[2][2]) {
	long long tmp[2][2] = {0};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			r[i][j] = tmp[i][j] % 1000000007;
		}
	}
}

int main () {
	long long t, ans[2][2] = {1, 0, 0, 1}, a[2][2] = {1, 1, 1, 0}, r[2][2];
	scanf("%lld", &t);
	while (t) {
		if (t & 1) {
			mulm(ans, a, r);
			memcpy(ans, r, sizeof(ans));
		}
		mulm(a, a, r);
		memcpy(a, r, sizeof(a));
		t >>= 1;
	}
	printf("%lld\n", ans[0][0]);
	return 0;
}
