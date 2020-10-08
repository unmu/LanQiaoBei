Anagrams指的是具有如下特性的两个单词：在这两个单词当中，每一个英文字母（不区分大小写）所出现的次数都是相同的。例如，Unclear和Nuclear、Rimon和MinOR都是Anagrams。编写一个程序，输入两个单词（只包含英文字母），然后判断一下，这两个单词是否是Anagrams。每一个单词的长度不会超过80个字符，而且是大小写无关的。
　　Input:长度不超过80个字符的两个单词，用空格隔开，不考虑字母大小写 （大小写无关）
　　Output: yes或者no
输入:
　　Rimon MinOR
输出:
　　yes

-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main () {
	string str[2];
	int cnt[26] = {0};
	cin >> str[0] >> str[1];
	if (str[0].length() != str[1].length()) {
		printf("no");
		return 0;
	}
	for (int i = 0; i < str[0].length(); i++) {
		int t = tolower(str[0][i]) - 'a';
		cnt[t]++;
	} 
	for (int i = 0; i < str[1].length(); i++) {
		int t = tolower(str[1][i]) - 'a';
		cnt[t]--;
	} 
	for (int i = 0; i < 26; i++) {
		if (cnt[i] != 0) {
			printf("no");
			return 0;
		} 
	}
	printf("yes");
	return 0;
}
