问题描述
　　地球人都知道，在国际象棋中，后如同太阳，光芒四射，威风八面，它能控制横、坚、斜线位置。
　　看过清宫戏的中国人都知道，后宫乃步步惊心的险恶之地。各皇后都有自己的势力范围，但也总能找到相安无事的办法。
　　所有中国人都知道，皇权神圣，伴君如伴虎，触龙颜者死......
　　现在有一个n*n的皇宫，国王占据他所在位置及周围的共9个格子，这些格子皇后不能使用（如果国王在王宫的边上，占用的格子可能不到9个）。当然，皇后也不会攻击国王。
　　现在知道了国王的位置（x,y）（国王位于第x行第y列，x,y的起始行和列为1），请问，有多少种方案放置n个皇后，使她们不能互相攻击。
输入格式
　　一行，三个整数，皇宫的规模及表示国王的位置
输出格式
　　一个整数，表示放置n个皇后的方案数
样例输入
8 2 2
样例输出
10
数据规模和约定
　　n<=12

-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
int n, ans = 0;
vector<vector<int> > v;
void dfs(int level) {
	if (level == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (v[level][i] == 2) {
			continue;
		}
		int flag = 1;
		for (int j = 0; j < level && flag; j++) {//竖向 
			if (v[j][i] == 1) {
				flag = 0;
			}
		}
		for (int x = level - 1, y = i - 1; x >= 0 && y >= 0 && flag; x--, y--) {//左斜上方向 
			if (v[x][y] == 1) {
				flag = 0;
			}
		}
		for (int x = level - 1, y = i + 1; x >= 0 && y < n && flag; x--, y++) {//右斜上方向 
			if (v[x][y] == 1) {
				flag = 0; 
			}
		}
		if (flag) {
			v[level][i] = 1;
			dfs(level + 1);
			v[level][i] = 0;
		}
	}
}

int main () {
	int x, y;
	scanf("%d %d %d", &n, &x, &y);
	v.resize(n, vector<int>(n));
	for (int i = x - 2 ; i <= x; i++) {
		for (int j = y - 2; j <= y; j++) {
			if (i >= 0 && i < n && j >= 0 && j < n) {
				v[i][j] = 2;
			} 
		}
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}
