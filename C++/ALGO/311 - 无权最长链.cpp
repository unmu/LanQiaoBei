问题描述
　　给定一个n节点m边的无圈且连通的图，求直径
输入格式
　　第一行两个数字n,m
　　接下来m行每行两个数字x,y,代表x,y之间有一条边
输出格式
　　要求用户的输出满足的格式。
　　例：输出1行，包含一个整数，表示矩阵中所有元素的和。
样例输入
一个满足题目要求的输入范例。
3 2
1 2
2 3
样例输出
与上面的样例输入对应的输出。
例：
2
数据规模和约定
　　数据不会很大
　　输入数据满足M=N-1

-----------------------------------------
//二维数组(邻接矩阵) + dfs法
#include<bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
vector<vector<int> > v, book;
void dfs(int u, int len) {
	for (int i = 1; i <= n; i++) {
		if (book[u][i] == 0 && v[u][i] == 1) {
			book[u][i] = 1;
			book[i][u] = 1;
			dfs(i, len + 1);
			book[u][i] = 0;
			book[i][u] = 0;
		}
	}
	ans = max(ans, len);
	return;
}
int main () {
	int t1, t2;
	scanf("%d %d", &n, &m);
	v.resize(n + 1, vector<int>(n + 1));
	book.resize(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &t1, &t2);
		v[t1][t2] = 1;
		v[t2][t1] = 1;
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 0);
	}
	printf("%d\n", ans);
	return 0;
}

--------------------------------------------
//Bellman-Ford
#include<bits/stdc++.h>
using namespace std;
int main () {
	int n, m, ans = 0, t1, t2;
	scanf("%d %d", &n, &m);
	vector<int> u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &t1, &t2);
		u.push_back(t1);
		v.push_back(t2);
		u.push_back(t2);
		v.push_back(t1);
	} 
	for (int i = 1; i <= n; i++) {
		vector<int> dis(n + 1, INT_MAX);
		dis[i] = 0;
		for (int j = 1; j < n; j++) {
			int flag = 1;
			for (int k = 0; k < 2 * m; k++) {
				if (dis[u[k]] != INT_MAX && dis[v[k]] > dis[u[k]] + 1) {
					dis[v[k]] = dis[u[k]] + 1;
					flag = 0;
				}
			}
			if (flag == 1) {
				break;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (dis[j] != INT_MAX) {
				ans = max(ans, dis[j]);//没有环，放心取max
			}
		} 
	}
	printf("%d\n", ans);
	return 0;
}
