#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> thoughts;
	thoughts.push_back(0);
	for (int i = 0; i < n; i++)	{
		int t;
		scanf("%d", &t);
		thoughts.push_back(t);
	}
	int maxLinkCounter = 0;
	for (int i = 1; i < thoughts.size(); i++)
	{	
		int thoughtLineLength = 0;
		int from = i - 1;
		while (thoughts[from] >= 0 && from != 0) {
			from = thoughts[from];
			thoughtLineLength++;
		}
		if (thoughtLineLength > maxLinkCounter) {
			maxLinkCounter = thoughtLineLength;
		}
	}
	printf("%d\n", maxLinkCounter);
	return 0;
}