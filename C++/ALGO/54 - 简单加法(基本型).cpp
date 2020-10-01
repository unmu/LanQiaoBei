问题描述
　　首先给出简单加法算式的定义：
　　如果有一个算式(i)+(i+1)+(i+2),(i>=0)，在计算的过程中，没有任何一个数位出现了进位，则称其为简单的加法算式。
　　例如：i=3时，3+4+5=12，有一个进位，因此3+4+5不是一个简单的加法算式；又如i=112时，112+113+114=339，没有在任意数位上产生进位，故112+113+114是一个简单的加法算式。

　　问题：给定一个正整数n，问当i大于等于0且小于n时,有多少个算式(i)+(i+1)+(i+2)是简单加法算式。其中n<10000。
输入格式
　　一个整数，表示n
输出格式
　　一个整数,表示简单加法算式的个数
样例输入
4

样例输出
3

-------------------------------------------
#include<bits/stdc++.h>
using namespace std;
string mytostr(int n) {
	if (n == 0) {
		return "0";
	}
	string str;
	while (n != 0) {
		str += n % 10 + '0';
		n /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}
int main () {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string a = mytostr(i), b = mytostr(i + 1), c = mytostr(i + 2);
		if (a.length() != b.length() || a.length() != c.length()) {
			continue;
		}
		string d = mytostr(2 * i + 1);
		if (a.length() != d.length()) {
			continue;
		}
		for (int i = a.length() - 1; i >= 0; i--) {
			if (d[i] < a[i] || d[i] < b[i]) {
				continue;
			}
		}
		d = mytostr(3 * i + 3);
		if (a.length() != d.length()) {
			continue;
		}
		for (int i = a.length() - 1; i >= 0; i--) {
			if (d[i] < a[i] || d[i] < b[i] || d[i] < c[i]) {
				continue;
			}
		}
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}
