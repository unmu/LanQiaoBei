问题描述
　　给出N个数字，求出有最大的最大质因数的那个数
输入格式
　　第一行：一个整数N。
　　接下来的N行，每行一个整数A_i，表示给出的那N个数字。
输出格式
　　第一行：一个整数，拥有最大的最大质因数的那个数。
样例输入
4
36
38
40
42
样例输出
38
数据规模和约定
　　60%的数据满足：N<=100
　　100%的数据满足：N<=2500,A_i<=20000

------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int p[20010] = {0}, book[20010] = {0};
int main () {
	int n, a, maxp = 0, ans;
	scanf("%d", &n);
	
	p[1] = 1;
	for (int i = 2; i < 20005; i++) {
		if (book[i] == 0) {
			p[i] = 1;
			for (int j = i + i; j < 20005; j += i) {
				book[j] = 1;
			} 
		}
	}
	
	while (n--) {
		scanf("%d", &a);
		for (int i = a; i >= 1; i--) {
			if (a % i == 0 && p[i] == 1) {
				if (maxp < i) {
					maxp = i;
					ans = a;
				}
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
