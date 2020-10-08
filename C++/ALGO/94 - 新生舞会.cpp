问题描述
　　新生舞会开始了。n名新生每人有三个属性：姓名、学号、性别。其中，姓名用长度不超过20的仅由大小写字母构成的字符串表示，学号用长度不超过10的仅由数字构成的字符串表示，性别用一个大写字符‘F’或‘M’表示。任意两人的姓名、学号均互不相同。换言之，每个人可被其姓名或学号唯一确定。给出m对两人的信息（姓名或学号），判断他们是否能共舞。两人能共舞的充要条件为两人性别相异。

输入
　　第一行一个整数n（2<=n<=1000），表示学生人数。接下来的n行每行依次包含一名新生的姓名、学号、性别，分别用一个空格隔开。
　　之后的一行是一个整数m(1<=m<=1000)，表示询问的数目。接着的m行每行包含两个信息（姓名或学号），保证两个信息不属于同一人，中间用一个空格隔开。

输出
　　对于每个询问输出一行，如果两人可以共舞，输出一个大写字母‘Y’，否则输出一个大写字母‘N’。


样例输入
　　4
　　John 10 M
　　Jack 11 M
　　Kate 20 F
　　Jim 21 M
　　3
　　John 11
　　20 Jack
　　Jim Jack


样例输出
　　N
　　Y
　　N

提示
　　可以把名字和学号都当成字符串处理。可以按以下流程实现。

　　#include<iostream>
　　#include<cstring>
　　using namespace std;

　　struct tstudent
　　{
　　char name[21];
　　char num[21];
　　char sex;
　　};

　　void readdata(tstudent student[], int n)
　　{
输入N个学生的信息
　　}

　　int findstudent(tstudent student[], int n, char* data)
　　{
　　if (data == NULL) return -1;

判断是否有某个学生的学号或名字等于data，如果有，函数返回该学生在student数组中的序号，否则返回-1
　　}

　　void solve(tstudent student[], int n, int m)
　　{
　　char x[21], y[21];
　　for (int i=0; i<m; i++) {
输入两个人的信息X、Y。通过调用findstudent函数判断这两个人能否成为舞伴
　　}
　　}

　　int main()
　　{
　　int n, m;
　　tstudent student[1010];

　　cin>>n;

　　readdata(student, n);
　　cin>>m;
　　solve(student, n, m);
　　}

------------------------------------------
#include<bits/stdc++.h>
using namespace std;
struct stu {
	string name;
	string id;
	char sex;
};
char getSex(string a, vector<stu> &v) {
	if (isalpha(a[0])) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i].name == a) {
				return v[i].sex;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].id == a) {
			return v[i].sex;
		}
	}
}
int main () {
	int n, m;
	scanf("%d", &n);
	vector<stu> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].id >> v[i].sex;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		if (getSex(a, v) != getSex(b, v)) {
			printf("Y");
		} else {
			printf("N");
		}
		printf("\n");
	}
	return 0;
}
