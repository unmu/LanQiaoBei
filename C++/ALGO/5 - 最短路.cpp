问题描述
给定一个n个顶点，m条边的有向图（其中某些边权可能为负，但保证没有负环）。请你计算从1号点到其他点的最短路（顶点从1到n编号）。

输入格式
第一行两个整数n, m。

接下来的m行，每行有三个整数u, v, l，表示u到v有一条长度为l的边。

输出格式
共n-1行，第i行表示1号点到i+1号点的最短路。
样例输入
3 3
1 2 -1
2 3 -1
3 1 2
样例输出
-1
-2
数据规模与约定
对于10%的数据，n = 2，m = 2。

对于30%的数据，n <= 5，m <= 10。

对于100%的数据，1 <= n <= 20000，1 <= m <= 200000，-10000 <= l <= 10000，保证从任意顶点都能到达其他所有顶点。

------------------------------------------
#include<bits/stdc++.h>
using namespace std;
vector<int> u, v, w, dis;
int main () {
	int n, m;
	scanf("%d %d", &n, &m);
	u.resize(m);
	v.resize(m);
	w.resize(m);
	dis.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	}
	for (int i = 2; i <= n; i++) {
		dis[i] = INT_MAX;
	}
	for (int i = 2; i <= n; i++) {
		int flag = 0;
		for (int j = 0; j < m; j++) {
			if (dis[u[j]] != INT_MAX && dis[v[j]] > dis[u[j]] + w[j]) {
				dis[v[j]] = dis[u[j]] + w[j];
				flag = 1;
			}
		}
		if (!flag) {
			break;
		}
	}
	for (int i = 2; i <= n; i++) {
		printf("%d\n", dis[i]);
	}
	return 0;
}

------------------------------------------------
Bellman-Ford算法
