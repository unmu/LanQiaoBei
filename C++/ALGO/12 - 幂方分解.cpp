问题描述
　　任何一个正整数都可以用2的幂次方表示。例如：
　　137=27+23+20
　　同时约定方次用括号来表示，即ab 可表示为a（b）。
　　由此可知，137可表示为：
　　2（7）+2（3）+2（0）
　　进一步：7= 22+2+20 （21用2表示）
　　3=2+20
　　所以最后137可表示为：
　　2（2（2）+2+2（0））+2（2+2（0））+2（0）
　　又如：
　　1315=210 +28 +25 +2+1
　　所以1315最后可表示为：
　　2（2（2+2（0））+2）+2（2（2+2（0）））+2（2（2）+2（0））+2+2（0）
输入格式
　　输入包含一个正整数N（N<=20000），为要求分解的整数。
输出格式
　　程序输出包含一行字符串，为符合约定的n的0，2表示（在表示中不能有空格）
  
-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
string dfs(int n) {
	if (n == 0) {
		return "0";
	}
	string str = "2";
	while (n != 0) {
		int cnt = 0, n2 = n, tmp = 1;
		while (n2 / 2) {
			cnt++;
			tmp *= 2;
			n2 /= 2;
		}
		if (cnt == 1) {
			str += "";
		} else {
			str += "(";
			str += dfs(cnt);
			str += ")";
		}
		n %= tmp;
		if (n) {
			str += "+2";
		}
	}
	return str;
}
int main () {
	int n;
	scanf("%d", &n);
	cout << dfs(n);
	return 0;
} 
