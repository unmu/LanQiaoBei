问题描述
　　给定某整数数组和某一整数b。要求删除数组中可以被b整除的所有元素，同时将该数组各元素按从小到大排序。如果数组元素数值在A到Z的ASCII之间，替换为对应字母。元素个数不超过100，b在1至100之间。
输入格式
　　第一行为数组元素个数和整数b
　　第二行为数组各个元素
输出格式
　　按照要求输出
样例输入
7 2
77 11 66 22 44 33 55

样例输出
11 33  55 M

----------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	int n, b, tmp;
	scanf("%d %d", &n, &b);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp % b != 0) {
			v.push_back(tmp);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (i != 0) {
			printf(" ");
		}
		if (v[i] >= 'A' && v[i] <= 'Z') {
			printf("%c", v[i]);
		} else {
			printf("%d", v[i]);
		}
	}
	return 0;
}
