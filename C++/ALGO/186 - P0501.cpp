输入两个无符号整数x, y, 用位操作实现无符号整数的乘法运算。不用考虑整数的溢出。
输入：
　　235 657
输出：
　　154395

-----------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
unsigned int add(unsigned int x, unsigned int y) {
	while (y) {		//y同时充当进位，进位为零即退出循环 
		int s = x ^ y;			// 异或，求加，s充当接下来的加数 
		int r = (x & y) << 1; 	// 相与，求进位，r在相与的基础上左移 充当接下来的加数 
		x = s;
		y = r;
	}
	return x; 
}
unsigned int multi(unsigned int x, unsigned int y) {
	int ans = 0;
	while (x) {
		if (x & 1) { 
			ans = add(ans, y);
		}
		y <<= 1; 
		x >>= 1;	// x每次往后移一位，x&1取到x的最后一位 
	}
	return ans;
}
int main () {
	unsigned int x, y;
	scanf("%u %u", &x, &y);
	printf("%u", multi(x, y));
	return 0;
} 

--------------------------------------------------
鸣谢
	https://blog.csdn.net/qq_42835910/article/details/86715893
