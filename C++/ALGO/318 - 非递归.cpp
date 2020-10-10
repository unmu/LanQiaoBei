问题描述
　　当x>1时，Hermite多项式的定义见第二版教材125页。用户输入x和n，试编写“非递归”函数，输出对应的Hermite多项式的值。其中x为float型，n为int型。
输入格式
　　x n
输出格式
　　对应多项式的值
样例输入
一个满足题目要求的输入范例。
例：
3.6 4
样例输出
与上面的样例输入对应的输出。
例：
2077.31
数据规模和约定
　　x>1
　　n为自然数

--------------------------------------------
#include<bits/stdc++.h>
using namespace std;
float fun(float x, int n) {
	if (n == 0) {
		return 1;
	} 
	if (n == 1) {
		return 2 * x;
	}
	return 2 * x * fun(x, n - 1) - 2 * (n - 1) * fun(x, n - 2);
}
int main () {
	float x;
	int n;
	scanf("%f %d", &x, &n);
	cout << fun(x, n);
	return 0;
}
