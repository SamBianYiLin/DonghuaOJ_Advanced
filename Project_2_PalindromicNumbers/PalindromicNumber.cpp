#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int> palindromics;
void FindPalindromicNumberByString(int num) {
	if (num <= 999) {
		num = 1000;
	}
	for (int i = num; i <= 9999; i++)	{
		string str = to_string(i);
		string rev_str = str;
		reverse(rev_str.begin(), rev_str.end());
		if (str == rev_str) palindromics.push_back(stoi(str));
		else continue;
	}
}
void FindPalindromicNumberByInteger(int num) {
	if (num <= 999) {
		num = 1000;
	}
	for (int i = num; i <= 9999; i++) {
		int ori = i;
		int rev = 0;
		while (i > 0) {
			rev = rev * 10 + i % 10;
			i /= 10;
		}
		//	printf("%d\n", rev);
		i = ori;
		if (ori == rev) {
			palindromics.push_back(ori);
		}
		else continue;
	}
}
int main() {
	int n;
	while (scanf("%d", &n) > 0) {
		palindromics.clear();
		//	方法一：使用string与reverse函数实现回文数的判断
		//	FindPalindromicNumberByString(n);
		//	方法二：使用int类型的循环实现回文数的判断
			FindPalindromicNumberByInteger(n);
		for (int i = 0; i < palindromics.size(); i++) {
			printf("%d\n", palindromics[i]);
		}
	}	
	return 0;
}