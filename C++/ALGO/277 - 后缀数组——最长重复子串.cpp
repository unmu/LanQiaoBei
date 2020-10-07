问题描述
　　给定一个长度为n的数串，求至少出现k 次的最长重复子串的长度，这k 个子串可以重叠。保证有子串出现至少k次。
输入格式
　　第一行：两个整数n, k;
　　第二行：2到n + 1行：n个整数，这n个整数组成了一个数串。
输出格式
　　一个整数，表示最长重复子串的长度。
样例输入
8 2
1
2
3
2
3
2
3
1
样例输出
4
数据规模和约定
　　0 ≤ n ≤ 20000, 2 ≤ k ≤ n，0≤ 数串中的整数≤ 1000000

------------------------------------------
#include<bits/stdc++.h>
using namespace std;
string trans(vector<int> &v, int i, int j) {
	string str;
	for (int p = i; p < j; p++) {
		int tmp = v[p];
		string num;
		if (tmp == 0) {
			num = "0";
		} else {
			while (tmp != 0) {
				num += tmp % 10 + '0';
				tmp /= 10;
			}
			reverse(num.begin(), num.end());
		}
		str += (num + '#');
	}
	return str;
}
int main () {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> v(n);
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = n - k + 1; i >= 1; i--) {
		for (int j = 0; j + i <= n; j++) {
			mp[trans(v, j, j + i)]++;
			if (mp[trans(v, j, j+ i)] == k) {
				printf("%d\n", i);
				return 0;
			}
		}
	}
	return 0;
}
