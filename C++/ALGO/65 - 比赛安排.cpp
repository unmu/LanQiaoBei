问题描述
　　设有有2 n（n<=6）个球队进行单循环比赛，计划在2 n – 1天内完成，每个队每天进行一场比赛。设计一个比赛的安排，使在2 n – 1天内每个队都与不同的对手比赛。
输入格式
　　输入文件matchplan.in共一行，输入n的数值。
输出格式
　　输出文件matchplan.out共（2 n – 1）行，第i行输出第i天的比赛安排。
　　格式为：<i> A-B，C-D，……。其中i是天数，A，B分别为比赛双方的编号，每行共2 n-1个比赛场次。
样例输入
2
样例输出
<1>1-2,3-4
<2>1-3,2-4
<3>1-4,2-3

-----------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
int main () {
	int n, cnt = 1;
	scanf("%d", &n);
	n = pow(2, n);
	vector<vector<int> > a; // 记录各队跟哪些队比赛过
	a.resize(n + 1, vector<int>(n + 1));
	for (int i = 1; i < n; i++) {
		printf("<%d>", i);
		vector<int> b(n + 1); // 记录当前有哪些队的安排已经确定
		for (int j = 1; j <= n; j++) {
			if (b[j] == 1) {
				continue;
			}
			for (int k = 1; k <= n; k++) {
				if (j == k || a[j][k] == 1 || b[k] == 1) {
					continue;
				}
				printf("%d-%d ", j, k);
				b[j] = 1;
				b[k] = 1;
				a[j][k] = 1;
				a[k][j] = 1;
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
