编程实现两个复数的运算。设有两个复数 和 ，则他们的运算公式为：

　　要求：（1）定义一个结构体类型来描述复数。
　　（2）复数之间的加法、减法、乘法和除法分别用不用的函数来实现。
　　（3）必须使用结构体指针的方法把函数的计算结果返回。
　　说明：用户输入：运算符号(+,-,*,/) a b c d.
　　输出：a+bi，输出时不管a,b是小于0或等于0都按该格式输出，输出时a,b都保留两位。

输入：
　　- 2.5 3.6 1.5 4.9
输出：
　　1.00+-1.30i
  
------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	char ch;
	double a, b, c, d;
	double m, n;
	scanf("%c %lf %lf %lf %lf", &ch, &a, &b, &c, &d);
	if (ch == '+') {
		m = a + c;
		n = b + d;
	} else if (ch == '-') {
		m = a - c;
		n = b - d;
	} else if (ch == '*') {
		m = a * c - b * d;
		n = a * d + b * c;
	} else if (ch == '/') {
		int fm = c * c + d * d;
		m = (a * c + b * d) / fm;
		n = (b * c - a * d) / fm;
	}
	printf("%.2lf+%.2lfi", m, n);
	return 0;
}
