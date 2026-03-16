#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main() {
	int n;
	char arr[1000];
	scanf("%d %s", &n, arr);
	string str = arr;
	if (n < 4) {
		printf("-1\n");
		return 0;
	}
	queue<string> toVisit;
	unordered_map<string, int> distanceMap;
	distanceMap.insert({str,0});
	toVisit.push(str);
	while (!toVisit.empty()) {
		string current = toVisit.front();
		toVisit.pop();
		if (current.find("2012") != string::npos) {
			printf("%d\n", distanceMap[current]);
			return 0;
		}
		for (int i = 0; i < current.size() - 1; i++) {
			string next = current;
			char t = next[i];
			next[i] = next[i + 1];
			next[i + 1] = t;
			//	next未出现过
			if (distanceMap.count(next) == 0) {
				toVisit.push(next);
				distanceMap.insert({ next,distanceMap[current] + 1 });
			}
		}
	}
	if (toVisit.empty()) {
		printf("-1\n");
	}
	return 0;
}