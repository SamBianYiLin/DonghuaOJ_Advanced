#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	vector<string> str;
	char t[5];
	while (scanf("%s", t) != EOF) {
		str.push_back(t);
	}
	if (str.size() != 52) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == "J") str[i] = "11";
		else if (str[i] == "Q") str[i] = "12";
		else if (str[i] == "K") str[i] = "13";
		else {
			continue;
		}
	}
	vector<string> cardHeap;
	for (int i = 0; i < str.size(); i++) {
		int top = stoi(str[i]);
		if (cardHeap.size() >= top) {
			cardHeap.insert(cardHeap.begin() + top,str[i]);
		}
		else if (cardHeap.size() < top) {
			cardHeap.push_back(str[i]);
		}
	}
	for (int i = 0; i < cardHeap.size(); i++) {
		if (cardHeap[i] == "11") cardHeap[i] = "J";
		else if (cardHeap[i] == "12") cardHeap[i] = "Q";
		else if (cardHeap[i] == "13") cardHeap[i] = "K";
		printf("%s ", cardHeap[i].c_str());
	}
	return 0;
}