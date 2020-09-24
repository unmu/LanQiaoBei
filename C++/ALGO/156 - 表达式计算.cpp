问题描述
　　输入一个只包含加减乖除和括号的合法表达式，求表达式的值。其中除表示整除。
输入格式
　　输入一行，包含一个表达式。
输出格式
　　输出这个表达式的值。
样例输入
1-2+3*(4-5)
样例输出
-4
数据规模和约定
　　表达式长度不超过100，表达式运算合法且运算过程都在int内进行。
  
------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int prior(char c) {
	if (c == '(' || c == ')') {
		return 1;
	}
	if (c == '+' || c == '-') {
		return 2;
	}
	if (c == '*' || c == '/') {
		return 3;
	}
}
int operate(int a, int b, char c) {
	if (c == '+') {
		return a + b;
	}
	if (c == '-') {
		return a - b;
	}
	if (c == '*') {
		return a * b;
	}
	if (c == '/') {
		return a / b;
	}
}
int main () {
	string str;
	getline(cin, str);
	stack<char> ch, mid;
	// 中缀表达式转后缀表达式 
	for (int i = 0; i < str.length(); i++) {
		int j = i;
		while (isdigit(str[j])) {
			mid.push(str[j]);
			j++;
		}
		if (j != i) {
			i = j - 1;
			mid.push('#');
			continue;
		}
		if (!isdigit(str[j])) {
			if (ch.empty() || str[j] == '(' || prior(str[j]) > prior(ch.top())) {
				ch.push(str[j]);
			} else if (str[j] == ')') {
				while (ch.top() != '(') {
					mid.push(ch.top());
					ch.pop();
				}
				ch.pop();
			} else if (prior(str[j]) <= prior(ch.top())) {
				mid.push(ch.top());
				ch.pop();
				ch.push(str[j]);
			}
		}
	} 
	while (!ch.empty()) {
		mid.push(ch.top());
		ch.pop();
	}
	string str2;
	while (!mid.empty()) {
		str2 = mid.top() + str2;
		mid.pop();
	}
	// 通过后缀表达式进行计算 
	stack<int> num;
	for (int i = 0; i < str2.length(); i++) {
		int j = i, x = 0;
		while (isdigit(str2[j])) {
			x = x * 10 + str2[j] - '0';
			j++;
		}
		if (j != i) {
			num.push(x);
			i = j;
			continue;
		}
		int b = num.top();
		num.pop();
		int a = num.top();
		num.pop();
		num.push(operate(a, b, str2[j]));
	}
	printf("%d", num.top());
	return 0;
}
