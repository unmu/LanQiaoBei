问题描述
　　（图３.１－１）示出了一个数字三角形。 请编一个程序计算从顶至底的某处的一条路
　　径，使该路径所经过的数字的总和最大。
　　●每一步可沿左斜线向下或右斜线向下走；
　　●1＜三角形行数≤100；
　　●三角形中的数字为整数0，1，…99；


　　.
　　（图３.１－１）
输入格式
　　文件中首先读到的是三角形的行数。

　　接下来描述整个三角形
输出格式
　　最大总和（整数）
样例输入
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
样例输出
30
------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	int n, tmp;
	scanf("%d", &n);
	vector<vector<int>> v; 
	for (int i = 0; i < n; i++) {
		v.push_back({});
		for (int j = 0; j <= i; j++) {
			scanf("%d", &tmp);
			v[i].push_back(tmp);
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			v[i][j] += max(v[i + 1][j], v[i + 1][j + 1]);
		}
	}
	printf("%d\n", v[0][0]);
	return 0;
}
