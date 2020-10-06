问题描述
　　输入一段英文，不含标点，将这一段英文以单词为单位倒序输出
输入格式
　　一段英文（段内不含换行），以换行符结尾。
输出格式
　　一段英文（段内不含换行），以换行符结尾。
样例输入
aab TTR bbc loV DDE Znr CCD
样例输出
CCD Znr DDE loV bbc TTR aab
数据规模和约定
　　60%的数据保证单词长度不超过20，字符长度不超过10^3
　　100%的数据保证单词长度不超过10^5，字符长度不超过10^6
  
---------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	string str, str2;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		int j = i;
		while (str[j] != ' ' && j < str.length()) {
			j++;
		}
		if (j != i) {
			str2 = str.substr(i, j - i) + str2;
			i = j - 1;
		} else {
			str2 = str[i] + str2;
		}
	}
	printf("%s\n", str2.c_str());
	return 0;
}
