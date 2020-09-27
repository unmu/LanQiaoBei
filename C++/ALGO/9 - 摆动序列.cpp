问题描述
　　如果一个序列满足下面的性质，我们就将它称为摆动序列：
　　1. 序列中的所有数都是不大于k的正整数；
　　2. 序列中至少有两个数。
　　3. 序列中的数两两不相等；
　　4. 如果第i – 1个数比第i – 2个数大，则第i个数比第i – 2个数小；如果第i – 1个数比第i – 2个数小，则第i个数比第i – 2个数大。
　　比如，当k = 3时，有下面几个这样的序列：
　　1 2
　　1 3
　　2 1
　　2 1 3
　　2 3
　　2 3 1
　　3 1
　　3 2
　　一共有8种，给定k，请求出满足上面要求的序列的个数。
输入格式
　　输入包含了一个整数k。（k<=20）
输出格式
　　输出一个整数，表示满足要求的序列个数。
  
-------------------------------------------
// DFS
#include<bits/stdc++.h>
using namespace std;
void dfs(int &k, int j, int a[], int tmp[], int &ans) {
	if (j == 2) {
		ans++;
	} else if (j > 2) {
		int i = j - 1;
		if ((tmp[i - 1] - tmp[i - 2]) * (tmp[i] < tmp[i - 2]) < 0) {
			ans++;
		} else {
			return;
		}
	}
	for (int i = 0; i < k; i++) {
		if(a[i] == 0) {
			tmp[j] = i; 
			a[i] = 1;
			dfs(k, j + 1, a, tmp, ans);
			a[i] = 0;
		}
	}
	return;
}
int main () {
	int k, ans = 0;
	scanf("%d", &k);
	int a[k] = {0}, tmp[k];
	dfs(k, 0, a, tmp, ans);
	printf("%d\n", ans);
	return 0;
} 

----------------------------------------------
// DP 画出dp[][]的表，找到规律
#include<bits/stdc++.h>
using namespace std;
int main () {
	int k;
	scanf("%d", &k);
	vector<vector<int> > dp;
	dp.resize(k + 1, vector<int>(k + 1));
	for (int i = 2; i <= k; i++) {
		for (int j = 2; j <= i; j++) {
			if (i == j) {
				dp[i][j] = 2;
			} else if (j == 2) {
				dp[i][j] = i * (i - 1);
			} else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += dp[k][i]; 
	}
	printf("%d\n", sum);
	return 0;
}

------------------------------------------------------------
鸣谢
https://blog.csdn.net/priestessofbirth/article/details/79257400
