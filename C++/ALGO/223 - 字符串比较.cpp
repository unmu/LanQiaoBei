问题描述
　　strncmp函数的原型为：int strncmp(char *s, char *t, int n);，其功能是比较字符串s和t的前n个字符。如果s<t，返回-1；如果s=t，返回0；如果s>t，返回1。请自己编程实现该函数，并编写一个程序来测试其正确性。
　　输入格式：输入有三行，第一行为字符串s，第二行为字符串t，第三行为整数n。
　　输出格式：输出只有一个整数，即比较结果。
输入输出样例
样例输入
world
word
4
样例输出
1

--------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int strncmp(string a, string b, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			return 1;
		} else if (a[i] < b[i]) {
			return -1;
		}
	}
	return 0;
}
int main () {
	string str1, str2;
	int n;
	getline(cin, str1);
	getline(cin, str2);
	scanf("%d", &n);
	printf("%d\n", strncmp(str1, str2, n));
	return 0;
}
