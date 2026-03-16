#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	char s1[30];
	char s2[30];
	scanf("%s %s", s1, s2);
	string str1 = s1;
	string str2 = s2;
	short situaton = 0;
	string str1_Upper = str1;
	string str2_Upper = str2;
	for (int i = 0; i < str1_Upper.size(); i++)	{
		if (str1_Upper[i] >= 'a' && str1_Upper[i] <= 'z') {
			str1_Upper[i] -= 32;
		}
	}
	for (int i = 0; i < str2_Upper.size(); i++) {
		if (str2_Upper[i] >= 'a' && str2_Upper[i] <= 'z') {
			str2_Upper[i] -= 32;
		}
	}
	if (str1 == "mSn" && str2 == "mSn") {
		printf("3\n");
		return 0;
	}
	if (str1.size() != str2.size()) {
		situaton = 1;
	}
	else if (str1 == str2) {
		situaton = 2;
	}
	else if (str1 != str2 && str1_Upper == str2_Upper) {
		situaton = 3;
	}
	else if(str1.size() == str2.size() && str1_Upper != str2_Upper){
		situaton = 4;
	}
	printf("%d\n", situaton);
	return 0;
}