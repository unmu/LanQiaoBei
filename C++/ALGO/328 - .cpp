问题描述
　　对一个字符串中的所有单词，如果单词的首字母不是大写字母，则把单词的首字母变成大写字母。在字符串中，单词之间通过空白符分隔，空白符包括：空格(' ')、制表符('\t')、回车符('\r')、换行符('\n')
输入格式
　　输入一行：待处理的字符串（长度小于80）
输出格式
　　输出一行：转换后的字符串。
样例输入
if so, you already have a google account. you can sign in on the right.
样例输出
If So, You Already Have A Google Account. You Can Sign In On The Right.

------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (isalpha(str[i]) && (i == 0 || !isalpha(str[i - 1]))) {
			str[i] = toupper(str[i]);
		}
	}
	cout << str;
	return 0;
}
