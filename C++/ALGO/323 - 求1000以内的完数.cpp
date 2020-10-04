问题描述
　　如果一个数恰好等于它的所有因子（包括1但不包括自身）之和，则称之为“完数”。例如6的因子是1，2，3，且6=1+2+3，因此6是完数。编写程序找出1000之内的所有完数。注意1不是完数。
输入格式
　　无
输出格式
　　如有多个完数，则分行输出，每行输出一个完数。（注意，不要输出其他任何多余字符）

------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int p[1010] = {0}, book[1010] = {0};
int main () {
	p[1] = 1;
	for (int i = 2; i < 1005; i++) {
		if (book[0] == 0) {
			p[i] = 1;
			for (int j = i + i; j < 1005; j += i) {
				book[j] = 1;
			}
		}
	}
	for (int i = 6; i <= 1000; i++) {
		vector<int> v;
		int x = i;
		for (int j = i - 1; j >= 1; j--) {
			if (i % j == 0 && p[j] == 1) {
				v.push_back(j);
			}
		}
		for (int i = 0; i < v.size(); i++) {
			x -= v[i];
		}
		if (x == 0) {
			printf("%d\n", i);
		}
	}
	return 0;
}
