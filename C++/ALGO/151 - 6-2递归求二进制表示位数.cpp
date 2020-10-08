问题描述
　　给定一个十进制整数，返回其对应的二进制数的位数。例如，输入十进制数9，其对应的二进制数是1001，因此位数是4。
样例输入
一个满足题目要求的输入范例。
9
样例输出
与上面的样例输入对应的输出。

数据规模和约定
　　输入数据中每一个数的范围。
　　例：输入在int表示范围内。

-------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int fun(int n) {
	if (n == 1) {
		return 1;
	}
	return 1 + fun(n / 2);
}
int main () {
	int n;
	scanf("%d", &n);
	if (n == 0) {
		printf("0");
	} else {
		printf("%d", fun(n));
	}
	return 0;
}
