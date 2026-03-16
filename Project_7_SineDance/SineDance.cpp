#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string An(int n) {
	string res = "";
	for (int i = 1; i <= n; i++){
		if (i == n) {
			res = res + "sin(" + to_string(i);
		}
		else {
			res = res + "sin(" + to_string(i) + (i % 2 == 0 ? "-" : "+");
		}
	}
	for (int i = 0; i < n; i++){
		res += ")";
	}
	return res;
}
string Sn(int n) {
	string res = "";
	for (int i = 1; i < n; i++){
		res += "(";
	}
	for (int i = 0; i < n; i++)	{
		string AnStr = An(i + 1);
		if (i == n - 1) {
			res = res + AnStr + "+" + to_string(n - i);
		}
		else {
			res = res + AnStr + "+" + to_string(n - i) + ")";
		}
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%s\n", Sn(n).c_str());
	return 0;
}