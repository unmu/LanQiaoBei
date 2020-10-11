问题描述
　　模拟程序型计算器，依次输入指令，可能包含的指令有


　　1. 数字：'NUM X'，X为一个只包含大写字母和数字的字符串，表示一个当前进制的数
　　2. 运算指令：'ADD','SUB','MUL','DIV','MOD'，分别表示加减乘，除法取商，除法取余
　　3. 进制转换指令：'CHANGE K'，将当前进制转换为K进制(2≤K≤36)
　　4. 输出指令：'EQUAL'，以当前进制输出结果
　　5. 重置指令：'CLEAR'，清除当前数字


　　指令按照以下规则给出：
　　数字，运算指令不会连续给出，进制转换指令，输出指令，重置指令有可能连续给出
　　运算指令后出现的第一个数字，表示参与运算的数字。且在该运算指令和该数字中间不会出现运算指令和输出指令
　　重置指令后出现的第一个数字，表示基础值。且在重置指令和第一个数字中间不会出现运算指令和输出指令
　　进制转换指令可能出现在任何地方


　　运算过程中中间变量均为非负整数，且小于2^63。
　　以大写的'A'~'Z'表示10~35
输入格式
　　第1行：1个n，表示指令数量
　　第2..n+1行：每行给出一条指令。指令序列一定以'CLEAR'作为开始，并且满足指令规则
输出格式
　　依次给出每一次'EQUAL'得到的结果
样例输入
7
CLEAR
NUM 1024
CHANGE 2
ADD
NUM 100000
CHANGE 8
EQUAL
样例输出
2040

---------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
long long cul(long long a, long long b, string op) {
	if (op == "ADD") {
		return a + b;
	}
	if (op == "SUB") {
		return a - b;
	}
	if (op == "MUL") {
		return a * b;
	}
	if (op == "DIV") {
		return a / b;
	}
	if (op == "MOD") {
		return a % b;
	}
}
int main () {
	int n, jz = 10, flag = 0, iscul = 0;
	long long ans = 0, num = 0;
	string str, op;
	scanf("%d", &n);
	getchar();
	for (int k = 0; k < n; k++) {
		getline(cin, str);
		if (str == "CLEAR") {
			ans = 0;
			flag = 1;
		} else if (str == "EQUAL") {
			if (ans == 0 || jz == 10) {
				printf("%lld\n", ans);
				continue;
			}
			string str2;
			long long ans2 = ans;
			while (ans2 != 0) {
				if (jz > 10) {
					if (ans2 % jz >= 10) {
						str2 += (ans2 % jz + 'A' - 10);
					} else {
						str2 += (ans2 % jz + '0');
					}
				} else {
					str2 += (ans2 % jz + '0');
				}
				ans2 /= jz;
			}
			reverse(str2.begin(), str2.end());
			cout << str2 << endl; 
		} else if (str.substr(0, 3) == "NUM") {
			num = 0;
			for (int i = 4; i < str.length(); i++) {
				if (isalpha(str[i])) {
					num = num * jz + str[i] - 'A' + 10;
				} else {
					num = num * jz + str[i] - '0';
				}
			}
			if (flag == 1) {
				ans = num;
				flag = 0;
			}
			if (iscul == 1) {
				ans = cul(ans, num, op);
				iscul = 0;
			}
		} else if (str.substr(0, 6) == "CHANGE") {
			jz = 0;
			for (int i = 7; i < str.length(); i++) {
				jz = jz * 10 + str[i] - '0';
			}
		} else {
			iscul = 1;
			op = str;
		}
	}
} 
