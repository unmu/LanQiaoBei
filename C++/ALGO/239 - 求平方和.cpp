问题描述
　　请用函数重载实现整型和浮点习型的两个数的平方和计算
输入格式
　　测试数据的输入一定会满足的格式。
　　2 2（2行2列，第1行整型，第2行浮点型）
输出格式
　　要求用户的输出满足的格式。
　　2 1（2行1列，第1行整型，第2行浮点型）
样例输入
一个满足题目要求的输入范例。
例：
2 2
3 4
3.1 4.1
样例输出
与上面的样例输入对应的输出。
例：
25
26.42
数据规模和约定
　　输入数据中每一个数的范围。
　　例：0<n,m<100, 0<=矩阵中的每个数<=1000。

------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int myMul(int n, int m) {
	return n * n + m * m;
}
double myMul(double a, double b) {
	return a * a + b * b;
} 
int main () {
	int n, m;
	cin >> n >> m;
	cout << myMul(n, m) << endl;
	double a, b;
	cin >> a >> b;
	cout << myMul(a, b) << endl;
	return 0;
}
