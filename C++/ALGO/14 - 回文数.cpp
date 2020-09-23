问题描述
　　若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。
　　例如：给定一个10进制数56，将56加65（即把56从右向左读），得到121是一个回文数。

　　又如：对于10进制数87：
　　STEP1：87+78 = 165 STEP2：165+561 = 726
　　STEP3：726+627 = 1353 STEP4：1353+3531 = 4884

　　在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。

　　写一个程序，给定一个N（2<=N<=10或N=16）进制数M（其中16进制数字为0-9与A-F），求最少经过几步可以得到回文数。
　　如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible!”
输入格式
　　两行，N与M
输出格式
　　如果能在30步以内得到回文数，输出“STEP=xx”（不含引号），其中xx是步数；否则输出一行”Impossible!”（不含引号）
样例输入
9
87
样例输出
STEP=6

-------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int chToDig(char c) {
	if (c <= '9' && c >= '0') {
		return c -'0';
	} else {
		return c - 'A' + 10; 
	}
}
char digToCh(int x) {
	if (x < 10) {
		return '0' + x;
	} else {
		return 'A' + x - 10;
	}
}
string add(string a, int n) {
	string b = a;
	reverse(b.begin(), b.end());
	int c[2] = {0};
	for (int i = 0; i < a.length(); i++) {
		int x, y;
		x = chToDig(a[i]);
		y = chToDig(b[i]);
		c[0] = c[1];
		c[1] = (x + y + c[0]) / n;
		a[i] = digToCh((x + y + c[0]) % n);
	}
	if (c[1] != 0) {
		a += '1';
	}
	reverse(a.begin(), a.end());
	return a;
}
bool isP(string s) {
	for (int i = 0; i <= s.length() / 2; i++) {
		if (s[i] != s[s.length() - i - 1]) {
			return false;
		}
	}
	return true;
}
int main () {
	int n, cnt = 0;
	string m;
	scanf("%d", &n);
	getchar();
	getline(cin, m);
	while (cnt <= 30) {
		if (isP(m)) {
			printf("STEP=%d\n", cnt);
			return 0;
		}
		m = add(m, n);
		cnt++;
	}
	printf("Impossible!\n");
	return 0;
}
