问题描述
　　有n*n的方格，其中有m个障碍，第i个障碍会消耗你p[i]点血。初始你有C点血，你需要从（1,1）到（n,n），并保证血量大于0，求最小步数。
输入格式
　　第一行3个整数n,m,c，表示棋盘大小、障碍数量和你的血量
　　接下来m行，每行描述一个障碍。包含三个整数x y p，分别表示障碍在第x行第y列，消耗血量为p。
输出格式
　　如果可以到输出步数，如果不可以，输出"No"。
样例输入
10 10 10
2 8 35
1 10 25
9 9 63
5 6 46
2 6 43
8 7 92
5 3 54
3 3 22
7 9 96
9 10 13
样例输出
18
数据规模和约定
　　输入数据中每一个数的范围。
　　0<n,m<100,

--------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	int n, m, c, x, y, p;
	scanf("%d %d %d", &n, &m, &c);
	vector<vector<int> > a, dp;
	a.resize(n + 1, vector<int>(n + 1)); 
	dp.resize(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &p);
		a[x][y] = p;
	}
	dp[1][1] = c - a[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x = i - 1, y = j;
			if (x >= 1 && x <= n && y >= 1 && y <= n && dp[x][y] - a[i][j] > 0) {
				dp[i][j] = max(dp[i][j], dp[x][y] - a[i][j]);
			} 
			x = i, y = j - 1;
			if (x >= 1 && x <= n && y >= 1 && y <= n && dp[x][y] - a[i][j] > 0) {
				dp[i][j] = max(dp[i][j], dp[x][y] - a[i][j]);
			}
		}
	}
	if (dp[n][n] == 0) {
		printf("No\n");
	} else {
		printf("%d\n", 2 * (n - 1));
	}
	return 0;
}

--------------------------------
还是要用右下方向的动态规划来做
