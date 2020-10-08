问题描述
　　令二元函数f(x,y)=ax+by，a和b为整数，求一个表达式S的值。
　　只有满足以下要求的表达式才是合法的：
　　1.任意整数x是一个合法的表达式；
　　2.如果A和B都是合法的表达式，则f(A,B)也是一个合法的表达式。
输入格式
　　第一行两个数a和b；
　　第二行一个字符串S表示要求的表达式。
输出格式
　　一行一个数表示表达式S的值。
样例输入
1 2
f(1,f(1,-1))
样例输出
-1
数据规模和约定
　　S的长度不超过50，运算过程中所有变量不会超出int的范围。

------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int strToNum(string str) {
	int i = 0, neg = 1, num = 0;
	if (str[i] == '-') {
		neg = -1;
		i++;
	}
	for ( ; i < str.length(); i++) {
		num = num * 10 + str[i] - '0';
	}
	return num * neg;
}
int main () {
	int a, b;
	string str;
	scanf("%d %d", &a, &b);
	cin >> str;
	if (str[0] != 'f') {
		cout << str;
		return 0;
	}
	stack<int> stk;
	for (int i = 0; i < str.length(); i++) {
		if (i > 0 && str[i - 1] == '(' && (str[i] == '-' || isdigit(str[i]))) {
			int j = i;
			string num;
			while (str[j] != ',') {
				num += str[j];
				j++;
			}
			stk.push(strToNum(num));
			i = j - 1;
		} else if (i > 0 && str[i - 1] == ',' && str[i] != 'f') {
			int j = i;
			string num; 
			while (str[j] != ')') {
				num += str[j];
				j++;
			}
			i = j;
			int x = stk.top();
			stk.pop();
			int y = strToNum(num);
			stk.push(a * x + b * y);
		} else if (str[i] == ')') {
			int y = stk.top();
			stk.pop();
			int x = stk.top();
			stk.pop();
			stk.push(a * x + b * y);
		}
	}
	printf("%d\n", stk.top());
	return 0;
}
