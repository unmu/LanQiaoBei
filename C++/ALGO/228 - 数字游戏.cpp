问题描述
　　给定一个1～N的排列a[i]，每次将相邻两个数相加，得到新序列，再对新序列重复这样的操作，显然每次得到的序列都比上一次的序列长度少1，最终只剩一个数字。
　　例如:
　　3 1 2 4
　　4 3 6
　　7 9
　　16
　　现在如果知道N和最后得到的数字sum，请求出最初序列a[i]，为1～N的一个排列。若有多种答案，则输出字典序最小的那一个。数据保证有解。
输入格式
　　第1行为两个正整数n，sum
输出格式
　　一个1～N的一个排列
样例输入
4 16
样例输出
3 1 2 4
数据规模和约定
　　0<n<=10

-----------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int n, sum, a[12][12];
int cn(int n, int k) {
	int m = min(n, n - k);
	if (m == 0) {
		return 1;
	}
	if (a[n][k] != 0) {
		return a[n][k];
	}
	long long r = 1;
	for (int i = n - m + 1; i <= n; i++) {
		r *= i;
	}
	for (int i = 2; i <= m; i++) {
		r /= i;
	}
	a[n][k] = r;
	return r;
}
int main () {
	scanf("%d %d", &n, &sum);
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		v[i] = i;
	}
	int t = n - 1;
	do {
		int r = 0;
		for (int i = 1; i <= n; i++) {
			r += cn(t, i - 1) * v[i];
			if (r > sum) {
				break;
			}
		}
		if (r == sum) {
			break;
		}
	} while(next_permutation(v.begin(), v.end()));
	for (int i = 1; i <= n; i++) {
		printf("%d ", v[i]);
	}
	return 0;
}
