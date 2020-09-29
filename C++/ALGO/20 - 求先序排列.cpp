问题描述
　　给出一棵二叉树的中序与后序排列。求出它的先序排列。（约定树结点用不同的大写字母表示，长度<=8）。
输入格式
　　两行，每行一个字符串，分别表示中序和后序排列
输出格式
　　一个字符串，表示所求先序排列

　　样例输入
　　BADC
　　BDCA
样例输出
ABCD

-------------------------------------------
#include<bits/stdc++.h>
using namespace std;
void getPro(string in, string post, string &pro, int startIn, int startPost, int len) {
	if (len <= 0) {
		return;
	}
	char tmp = post[startPost + len - 1];
	pro += tmp;
	int i, start = startIn;
	for (i = 0 ; i < len; i++) {
		if (in[start] == tmp) {
			break;
		}
		start++;
	}
	int len1 = i, len2 = len - i - 1;
	getPro(in, post, pro, startIn, startPost, len1);
	getPro(in, post, pro, start + 1, startPost + len1, len2); 
}
int main () {
	string in, post, pro;
	getline(cin, in);
	getline(cin, post);
	getPro(in, post, pro, 0, 0, in.length());
	cout << pro << endl; 
	return 0;
}
