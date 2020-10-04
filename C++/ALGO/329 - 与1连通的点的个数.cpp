输入格式
　　输入的第一行包含两个整数n, m
　　n代表图中的点的个数，m代表边的个数
　　接下来m行，每行2个正整数，表示图中连通的两点。
输出格式
　　输出1个数，与1连通的点的个数。
样例输入
6 3
1 2
2 3
3 4
样例输出
4
数据规模和约定
　　n<=10000,m<=100000。

-------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	int n, m, f, t, cnt = 0;
	scanf("%d %d", &n, &m);
	vector<int> u, v, dis(n + 1);
	for (int i = 2; i <= n; i++) {
		dis[i] = INT_MAX;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &f, &t);
		u.push_back(f);
		v.push_back(t);
		v.push_back(f);
		u.push_back(t);
	}
	for (int i = 1; i < n; i++) {
		int flag = 0;
		for (int j = 0; j < 2 * m; j++) {
			if (dis[u[j]] != INT_MAX && dis[v[j]] > dis[u[j]] + 1) {
				dis[v[j]] = dis[u[j]] + 1;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dis[i] < INT_MAX) {
			cnt++;
		}
	}
	printf("%d\n", cnt); 
	return 0;
}
