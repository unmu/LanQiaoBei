问题描述
　　一个整数n的阶乘可以写成n!，它表示从1到n这n个整数的乘积。阶乘的增长速度非常快，例如，13!就已经比较大了，已经无法存放在一个整型变量中；而35!就更大了，它已经无法存放在一个浮点型变量中。因此，当n比较大时，去计算n!是非常困难的。幸运的是，在本题中，我们的任务不是去计算n!，而是去计算n!最右边的那个非0的数字是多少。例如，5! = 1*2*3*4*5 = 120，因此5!最右边的那个非0的数字是2。再如：7! = 5040，因此7!最右边的那个非0的数字是4。请编写一个程序，输入一个整数n(n<=100)，然后输出n! 最右边的那个非0的数字是多少。
　　输入格式：输入只有一个整数n。
　　输出格式：输出只有一个整数，即n! 最右边的那个非0的数字。
输入输出样例
样例输入
6
样例输出
2

------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
string digToStr(int n) {
	string str;
	while (n != 0) {
		str += (n % 10) + '0';
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
			if (i + j < r.length()) {
				c[1] = (r[i + j] - '0' + c[0] + (a[i] - '0') * (b[j] - '0')) / 10;
				r[i + j] = (r[i + j] - '0' + c[0] + (a[i] - '0') * (b[j] - '0')) % 10 + '0';
			} else {
				c[1] = (c[0] + (a[i] - '0') * (b[j] - '0')) / 10;
				r += (c[0] + (a[i] - '0') * (b[j] - '0')) % 10 + '0';
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
	int n;
	scanf("%d", &n);
	string ans = "1";
	for (int i = 2; i <= n; i++) {
		ans = mulStr(ans, digToStr(i));
	}
	for (int i = ans.length() - 1; i >= 0; i--) {
		if (ans[i] != '0') {
			printf("%c", ans[i]);
			break;
		}
	}
	return 0;
}

---------------------------------------------------
没有技巧，直接字符串形式大数相乘
