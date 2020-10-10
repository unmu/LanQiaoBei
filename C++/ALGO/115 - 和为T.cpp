问题描述
　　从一个大小为n的整数集中选取一些元素，使得它们的和等于给定的值T。每个元素限选一次，不能一个都不选。
输入格式
　　第一行一个正整数n，表示整数集内元素的个数。
　　第二行n个整数，用空格隔开。
　　第三行一个整数T，表示要达到的和。
输出格式
　　输出有若干行，每行输出一组解，即所选取的数字，按照输入中的顺序排列。
　　若有多组解，优先输出不包含第n个整数的；若都包含或都不包含，优先输出不包含第n-1个整数的，依次类推。
　　最后一行输出总方案数。
样例输入
5
-7 -3 -2 5 9
0
样例输出
-3 -2 5
-7 -2 9
2
数据规模和约定
　　1<=n<=22
　　T<=maxlongint
　　集合中任意元素的和都不超过long的范围

----------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int n, t, ans = 0;
vector<int> v, book;
void dfs(int k, int cnt, int sum) {
	if (sum == t && k < n - 1 && book[k + 1] == 1 && cnt != 0) {
		ans++;
		for (int i = 0; i < n; i++) {
			if (book[i]) {
				printf("%d ", v[i]);
			}
		}
		printf("\n");
	}
	if (k < 0) {
		return;
	}
	dfs(k - 1, cnt, sum);
	book[k] = 1;
	dfs(k - 1, cnt + 1, sum + v[k]);
	book[k] = 0;
	return;
}
int main () {
	scanf("%d", &n);
	v.resize(n);
	book.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	scanf("%d", &t);
	dfs(n - 1, 0, 0);
	printf("%d\n", ans);
	return 0;
}

--------------------------------------------
数组逆序，dfs，先考虑不加v[i]的情况，再考虑加上v[i]的情况。相当于一棵二叉树
把数据定义为全局，避免放置于dfs函数内导致运行超时
