问题描述
　　道德经曰：一生二，二生三，三生万物。
　　对于任意正整数n，我们定义d(n)的值为为n加上组成n的各个数字的和。例如，d(23)=23+2+3=28, d(1481)=1481+1+4+8+1=1495。
　　因此，给定了任意一个n作为起点，你可以构造如下一个递增序列：n,d(n),d(d(n)),d(d(d(n)))....例如，从33开始的递增序列为：
　　33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...
　　我们把n叫做d(n)的生成元，在上面的数列中，33是39的生成元，39是51的生成元，等等。有一些数字甚至可以有两个生成元，比如101，可以由91和100生成。但也有一些数字没有任何生成元，如42。我们把这样的数字称为寂寞的数字。
输入格式
　　一行，一个正整数n。
输出格式
　　按照升序输出小于n的所有寂寞的数字，每行一个。
样例输入
40
样例输出
1
3
5
7
9
20
31
数据规模和约定
　　n<=10000

-----------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	int n, s, k;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 1; i < n; i++) {
		s = i;
		k = i;
		while (k != 0) {
			s += k % 10;
			k /= 10;
		}
		if (s < n) {
			v[s] = 1;
		}
	}
	for (int i = 1; i < n; i++) {
		if (v[i] == 0) {
			printf("%d\n", i);
		}
	}
	return 0;
}
