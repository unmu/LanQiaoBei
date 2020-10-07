问题描述
　　我们知道，阶乘n!表示n*(n-1)*(n-2)*......*2*1, 类似的，可以定义多阶乘计算，例如：5！！=5*3*1,依次可以有n!...!(k个‘！’，可以简单表示为n(k)!)=n*(n-k)*(n-2k)*....（直到最后一个数<=0）。
　　现给定一组数据n、k、m,当m=1时，计算并输出n(1)!+n(2)!+......+n(k)!的值，m=2时计算并输出n(1)!+n(2)!+......+n(k)!的各个位上的数字之和。
输入格式
　　两行，第一行为n和k，第二行为m。
输出格式
　　一行,为n(1)!+n(2)!+......+n(k)!的值或n(1)!+n(2)!+......+n(k)!的各个位上的数字之和。
样例输入
5 1
2
样例输出
3
数据规模和约定
　　0 < k < n <= 20

----------------------------------------------
#include<bits/stdc++.h>
using namespace std;
long long fun(int n, int k) {
	if (n <= 0) {
		return 1;
	}
	return n * fun(n - k, k);
}
int main () {
	int n, k, m;
	long long num1 = 0, num2 = 0;
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= k; i++) {
		num1 += fun(n, i);
	}
	if (m == 1) {
		printf("%lld", num1);
	} else {
		while (num1 != 0) {
			num2 += (num1 % 10);
			num1 /= 10;
		}
		printf("%lld", num2);
	}
	return 0;
}
