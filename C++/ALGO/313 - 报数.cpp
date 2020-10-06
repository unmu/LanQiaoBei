问题描述
　　现有n个同学站成一圈，顺时针编号1至n。从1号同学开始顺时针1/2报数，报到1的同学留在原地，报到2的同学退出圆圈，直到只剩一名同学为止。问最后剩下的同学编号。
输入格式
　　仅一行，一个正整数n。
输出格式
　　仅一行，一个正整数。
样例输入
400
样例输出
289
数据规模和约定
　　n<=2000000
  
------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	int n, t;
	scanf("%d", &n);
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		v[i] = i;
	}
	int cnt = 1;
	t = n;
	while (t >= 0) {
		for (int i = 1; i <= n && t >= 0; i++) {
			if (t == 1) {
				if (v[i] != 0) {
					printf("%d\n", i);
					return 0;
				}
			} else if (v[i] != 0) {
				if (cnt == 2) {
					cnt--;
					v[i] = 0;
					t--;
				} else {
					cnt++;
				}
			}
		}
	}
	return 0;
}
