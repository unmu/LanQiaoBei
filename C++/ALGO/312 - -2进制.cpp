问题描述
　　给出1个十进制整数N，计算出它的-2进制表示。
输入格式
　　第一行：一个整数N，表示要转换的十进制数。
输出格式
　　第一行：N的-2进制表示。
样例输入
-13
样例输出
110111
数据规模和约定
　　100%的数据满足:|n|<=2000000000。
提示
　　负二进制：
　　有这样一个数100110，它是-2进制的数，将它转换成10进制数的方法是1*(-2)5 + 0*(-2)4 + 0*(-2)3 + 1*(-2)2 + 1*(-2)1 + 0*(-2)0 等于-30。

　　110111转换为负二进制数为：1*(-2)5 + 1*(-2)4 + 0*(-2)3 + 1*(-2)2 + 1*(-2)1 + 1*(-2)0 等于-13

　　在-2进制数中，每个位置上的数字只能是0或1。可以证明，每一个10进制数都可以表示成-2进制数，而且表示方式是唯一的。

----------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	int n;
	scanf("%d", &n);
	string s;
	if (n == 0) {
		printf("0");
		return 0;
	}
	while (n != 0) {
		int t = n % (-2);
		if (t < 0) {
			s += (t + '2');
			n = n / (-2) + 1;
		} else {
			s += t + '0';
			n /= (-2);
		}
	}
	reverse(s.begin(), s.end());
	printf("%s\n", s.c_str());
	return 0;
}
