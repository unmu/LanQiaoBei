问题描述
　　给定n和len，输出n!末尾len位。
输入格式
　　一行两个正整数n和len。
输出格式
　　一行一个字符串，表示答案。长度不足用前置零补全。
样例输入
6 5
样例输出
00720
数据规模和约定
　　n<=30, len<=10。

-----------------------------------------------
#include<bits/stdc++.h>
using namespace std;
string digToStr(int n) {
	string str;
	while (n != 0) {
		str += n % 10 + '0';
		n /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}
string mulStr(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string r;
	for (int i = 0; i < a.length(); i++) {
		int c[2] = {0};
		for (int j = 0; j < b.length(); j++) {
			c[0] = c[1];
			if (i + j >= r.length()) {
				c[1] = (c[0] + (a[i] - '0') * (b[j] - '0')) / 10;
				r += (c[0] + (a[i] - '0') * (b[j] - '0')) % 10 + '0';
			} else {
				c[1] = (c[0] + r[i + j] - '0' + (a[i] - '0') * (b[j] - '0')) / 10;
				r[i + j] = (c[0] + r[i + j] - '0' + (a[i] - '0') * (b[j] - '0')) % 10 + '0';
			}
		}
		if (c[1] != 0) {
			r += c[1] + '0';
		}
	}
	reverse(r.begin(), r.end());
	return r;
}
int main () {
	int n, m;
	string ans = "1", part;
	scanf("%d %d", &n, &m);
	for (int i = 2; i <= n; i++) {
		ans = mulStr(ans, digToStr(i));
	}
	for (int i = ans.length() - 1; i >= 0 && m > 0; i--, m--) {
		part += ans[i];
	}
	for (; m > 0; m--) {
		part += '0';
	}
	reverse(part.begin(), part.end());
	printf("%s\n", part.c_str());
	return 0;
}
