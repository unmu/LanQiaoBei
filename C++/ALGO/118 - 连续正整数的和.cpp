问题描述
　　78这个数可以表示为连续正整数的和，1+2+3，18+19+20+21，25+26+27。
　　输入一个正整数 n(<=10000)
　　输出 m 行(n有m种表示法)，每行是两个正整数a，b，表示a+(a+1)+...+b=n。
　　对于多种表示法，a小的方案先输出。
样例输入
78
样例输出
1 12
18 21
25 27

-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int cnt = 0, s = i, j = i + 1;
		for ( ; s < n; j++, cnt++) {
			s += j;
		}
		if (cnt >= 1 && s == n) {
			printf("%d %d\n", i, j - 1);
		}
	}
	return 0;
}
