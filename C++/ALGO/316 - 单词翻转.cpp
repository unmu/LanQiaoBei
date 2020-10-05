输入格式
　　输入包括一个英语句子。
输出格式
　　按单词的顺序把单词倒序输出
样例输入
I love you
样例输出
you love I
数据规模和约定
　　简单的字符串操作

----------------------------------------------
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
