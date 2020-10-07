问题描述
　　给你一个非零整数，让你求这个数的n次方，每次相乘的结果可以在后面使用，求至少需要多少次乘。如24：2*2=22（第一次乘），22*22=24（第二次乘），所以最少共2次；
输入格式
　　第一行m表示有m(1<=m<=100)组测试数据；
　　每一组测试数据有一整数n（0<n<=100000000）;
输出格式
　　输出每组测试数据所需次数s;
样例输入
3
2
3
4
样例输出
1
2
2

------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	int m, n;
	scanf("%d", &m);
	while(m--) {
		scanf("%d", &n);
		int sum = 0, i;
		for (i = 1; ; i += i) {
			if (i > n) {
				i /= 2;
				n -= i;
				sum--;
				break;
			} else if (i == n) {
				n = 0;
				break;
			} else {
				sum++;
			}
		}
		while (n > 0) {
			if (i <= n) {
				n -= i;
				sum++;
			}
			i /= 2;
		}
		printf("%d\n", sum);
	}
	return 0;
}

--------------------------------------------------
鸣谢
  https://blog.csdn.net/weixin_45269353/article/details/104755489
  
没有很复杂
先按*2增长的方式计数，再反过来计数
