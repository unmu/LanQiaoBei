问题描述
　　s01串初始为"0"
　　按以下方式变换
　　0变1，1变01
输入格式
　　1个整数(0~19)
输出格式
　　n次变换后s01串
样例输入
3
样例输出
101
数据规模和约定
　　0~19

-------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	string str = "0";
	int n;
	scanf("%d", &n);
	while (n--) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '0') {
				str[i] = '1';
			} else {
				str.insert(i, "0");
				i++;
			}
		}
	}
	printf("%s\n", str.c_str());
	return 0;
}
