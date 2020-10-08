问题描述
　　有n个人围成一圈，顺序排号（编号为1到n）。从第1个人开始报数(从1到3报数)，凡报到3的人退出圈子。从下一个人开始继续报数，直到剩下最后一个人，游戏结束。
　　问最后留下的是原来第几号的那位。
　　举个例子，8个人围成一圈：
　　1 2 3 4 5 6 7 8
　　第1次报数之后，3退出，剩下：
　　1 2 4 5 6 7 8 （现在从4开始报数）
　　第2次报数之后，6退出，剩下：
　　1 2 4 5 7 8 （现在从7开始报数）
　　第3次报数之后，1退出，剩下：
　　2 4 5 7 8 （现在从2开始报数）
　　第4次报数之后，5退出，剩下：
　　2 4 7 8 （现在从7开始报数）
　　第5次报数之后，2退出，剩下：
　　4 7 8 （现在从4开始报数）
　　第6次报数之后，8退出，剩下：
　　4 7 （现在从4开始报数）
　　最后一次报数之后，4退出，剩下：
　　7.
　　所以，最后留下来的人编号是7。
输入格式
　　一个正整数n，(1<n<10000)
输出格式
　　一个正整数，最后留下来的那个人的编号。
样例输入
8
样例输出
7
数据规模和约定
　　对于100%的数据，1<n<10000。

-----------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	int n, n2, cnt = 0;
	scanf("%d", &n);
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		v[i] = i;
	}
	n2 = n;
	while (n2 > 1) {
		for (int i = 1; i <= n && n2 > 1; i++) {
			if (v[i] != 0) {
				cnt++;
				if (cnt == 3) {
					cnt = 0;
					v[i] = 0;
					n2--;
				}
			}
			
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] != 0) {
			printf("%d", i);
			break;
		}
	}
	return 0;
} 
