问题描述
　　给定一个正整数n，求一个正整数p，满足p仅包含n的所有素因子，且每个素因子的次数不大于1
输入格式
　　一个整数，表示n
输出格式
　　输出一行，包含一个整数p。
样例输入
1000
样例输出
10
数据规模和约定
　　n<=10^12
　　样例解释：n=1000=2^3*5*3，p=2*5=10
  
---------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	long long n;
	vector<long long> v;
	int p = 1;
	scanf("%lld", &n);
	if (n <= 3) {
		printf("%lld", n);
		return 0;
	}
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);
		}
		while (n % i == 0) {
			n /= i;
		}
	}
	if (n > 1) {
		v.push_back(n);
	}
	for (int i = 0; i < v.size(); i++) {
		p *= v[i];
	}
	printf("%d", p);
	return 0;
}
