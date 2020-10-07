问题描述
　　小X的作业是老师给他布置的，题目很简单，求出第N个斐波那契数 mod P的值。小X怎么想也想也想不出来，只好求助于你了。
输入格式
　　第一行为数据组数T。
　　第二行开始，以下T行，每行为老师给小X布置的作业中的N和P。
输出格式
　　包含T行，每行是一个作业的答案。
样例输入
3
7 3
1000000 89
987654321 30000
样例输出
0
55
19111
数据规模和约定
　　对于50%的数据，T<=100，N<=10000。
　　对于100%的数据，T<=10000，N<=1000000000，P<=30000。
　　斐波那契数的第0个是1。

----------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int t, n, p;
void multi(long long ans[2][2], long long a[2][2], long long r[2][2]) {
	long long tmp[2][2];
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				tmp[i][j] += ans[i][k] * a[k][j];
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			r[i][j] = tmp[i][j] % p;
		}
	}
}
int main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &p);
		long long a[2][2] = {1, 1, 1, 0}, ans[2][2] = {1, 0, 0, 1}, r[2][2];
		n--;
		while (n) {
			if (n & 1) {
				multi(ans, a, r);
				memcpy(ans, r, sizeof(r));
			}
			multi(a, a, r);
			memcpy(a, r, sizeof(r));
			n >>= 1;
		}
		printf("%d\n", (ans[0][0] + ans[0][1]) % p);
	}
	return 0;
} 

------------------------------------------------------
鸣谢
  https://blog.csdn.net/qiaoermeng/article/details/105371550
  
运用推导矩阵公式和（矩阵）快速幂的方法
斐波那契数列公式：F(0) = 1, F(1) = 1, F(n) = F(n - 1) + F(n - 2) [F(n - 1) = F(n - 1) + 0 * F(n - 2)]
最终推导为：
|  F(n)  |  = |1 1|^(n - 1) *|F(1)|
|F(n - 1)|    |1 0|          |F(0)|
另 快速幂（求a^n%m）：
int ans = 1;
while (n) {
	if (n & 1) {//为奇数
		ans = (ans * a) % m;
	}
	a = (a * a) % m;
	n >>= 1; // 右移一位，相当于对2取整
}
cout << ans;
