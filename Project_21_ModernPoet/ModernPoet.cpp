#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
int main() {
	char s[2000];
	scanf("%s", s);
	string str = s;
	int maxPartRepeat = 1;
	for (int i = 1; i < str.length() - 1; i++)	{
		if (str.length() % i != 0) continue;
		bool allMatch = true;
		int counter = 1;
		string temp = "";
		for (int j = 0; j < i; j++) {
			temp.push_back(str[j]);
		}
		vector<string> matchesStr;
		for (int j = i; j < str.size(); j+=i) {
			if (str.size() - i >= 0) {
				matchesStr.push_back(str.substr(j, i));
			}
		}
		for (int count = 0; count < matchesStr.size(); count++)
		{
			if (temp != matchesStr[count]) {
				allMatch = false;
				break;
			}
			if(allMatch) counter++;
		}
		if (counter > maxPartRepeat) {
			maxPartRepeat = counter;
			//printf("%s %d\n", temp.c_str(),i);
		}
	}
	printf("%d\n", maxPartRepeat);
	return 0;
}