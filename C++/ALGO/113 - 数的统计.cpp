问题描述
　　在一个有限的正整数序列中，有些数会多次重复出现在这个序列中。
　　如序列：3，1，2，1，5，1，2。其中1就出现3次，2出现2次，3出现1 次，5出现1次。
　　你的任务是对于给定的正整数序列，从小到大依次输出序列中出现的数及出现的次数。
输入格式
　　第一行正整数n，表示给定序列中正整数的个数。
　　第二行是n 个用空格隔开的正整数x，代表给定的序列。
输出格式
　　若干行，每行两个用一个空格隔开的数，第一个是数列中出现的数，第二个是该数在序列中出现的次数。
样例输入
12
8 2 8 2 2 11 1 1 8 1 13 13
样例输出
1 3
2 3
8 3
11 1
13 2
数据规模和约定
　　数据：n<=1000；0<x<=1000,000。

------------------------------------------
#include<bits/stdc++.h>
using namespace std;
struct a {
	int num;
	int cnt;
};
int cmp(a x, a y) {
	return x.num < y.num;
} 
int main () {
	int n, t, cnt = 1;
	scanf("%d", &n);
	vector<a> v;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (mp[t] == 0) {
			mp[t] = cnt++;
		}
		if (cnt - 1 > v.size()) {
			v.push_back({t, 1});
		} else {
			v[mp[t] - 1].cnt++;
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].num, v[i].cnt);
	}
	return 0;
}
