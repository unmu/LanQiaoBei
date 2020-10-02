问题描述
　　从键盘输入一个含有括号的四则运算表达式，要求去掉可能含有的多余的括号，结果要保持原表达式中变量和运算符的相对位置不变，且与原表达式等价,不要求化简。另外不考虑'+'　　'-'用作正负号的情况，即输入表达式不会出现(+a)或(-a)的情形。
输入格式
　　表达式字符串，长度不超过255,　　并且不含空格字符。表达式中的所有变量都是单个小写的英文字母, 运算符只有加+减-乘*除/等运算符号。
输出格式
　　去掉多余括号后的表达式
样例输入
样例一：
a+(b+c)-d
样例二：
a+b/(c+d)
样例三：
(a*b)+c/d
样例四：
((a+b)*f)-(i/j)

样例输出
样例一：
a+b+c-d
样例二：
a+b/(c+d)
样例三：
a*b+c/d
样例四：
(a+b)*f-i/j

-------------------------------------------
#include<bits/stdc++.h>
using namespace std;
struct node {
	string str;
	int flag;
};
int prior(char a) {
	if (a == '(' || a == ')') {
		return 1;
	}
	if (a == '+' || a == '-') {
		return 2;
	}
	if (a == '*' || a == '/') {
		return 3;
	}
}
int main () {
	string str;
	getline(cin, str);
	stack<char> ch, mid;
	for (int i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			mid.push(str[i]);
		} else {
			if (ch.empty() || str[i] == '(' || prior(str[i]) > prior(ch.top())) {
				ch.push(str[i]);
			} else if (str[i] == ')') {
				while(ch.top() != '(') {
					mid.push(ch.top());
					ch.pop();
				}
				ch.pop();
			} else if (prior(str[i]) <= prior(ch.top())) {
				mid.push(ch.top());
				ch.pop();
				ch.push(str[i]);
			}
		}
	}// a-b+c*(d-e)
	while(!ch.empty()) {
		mid.push(ch.top());
		ch.pop();
	}
	string str2;
	while(!mid.empty()) {
		str2 += mid.top();
		mid.pop();
	}
	reverse(str2.begin(), str2.end());
	stack<node> ans;
	node a, b;
	for (int i = 0; i < str2.length(); i++) {
		if (isalpha(str2[i])) {
			string num;
			num += str2[i];
			ans.push({num, 0});
		} else {
			b = ans.top();
			ans.pop();
			a = ans.top();
			ans.pop();
			if (prior(str2[i]) == 2) {
				if (str2[i] == '-' && b.flag == 1) {
					b.str = "(" + b.str + ")";
				}
				ans.push({a.str + str2[i] + b.str, 1});
			} else {//prior(str2[i]) == 3
				if (a.flag == 1) {
					a.str = "(" + a.str + ")";
				}
				if (b.flag == 1) {
					b.str = "(" + b.str + ")";
				}
				ans.push({a.str + str2[i] + b.str, 2});
			}
		}
	}
	cout << ans.top().str << endl;
	return 0;
}

--------------------------------------------
按照计算表达式的方式走了一遍，先将中缀表达式转为后缀表达式，再处理后缀表达式根据情况添加括号
