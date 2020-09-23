问题描述
　　某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

　　输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数），计算这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。
输入格式
　　一行，为导弹依次飞来的高度
输出格式
　　两行，分别是最多能拦截的导弹数与要拦截所有导弹最少要配备的系统数
样例输入
389 207 155 300 299 170 158 65
样例输出
6
2

----------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	string s;
	int a, ans = -1, cnt = 0;
	getline(cin, s);
	stringstream ss;
//	ss.clear();
	ss.str(s);
	vector<int> v;
	while(ss >> a) { // ss.fail() == true 
		v.push_back(a);
	}
	vector<int> dp(v.size());
	while (v.size()) {
		cnt++;
		vector<int> path(v.size(), -1);
		int sp = -1;
		for (int i = 0; i < v.size(); i++) {
			dp[i] = 1;
			for  (int j = 0; j < i; j++) {
				if (v[i] <= v[j] && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					path[i] = j; //路径回溯 
					sp = i;
				}
			}
			ans = max(ans, dp[i]);
		}
		if (sp == -1) {
			v.erase(v.begin());
			continue;
		}
		while (sp != -1) {
			v[sp] = -1;
			int tmp = path[sp];
			sp = tmp;
		}
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] == -1) {
				v.erase(v.begin() + i);
			}
		}
	}
	printf("%d\n", ans);
	printf("%d\n", cnt);
	return 0;
}
