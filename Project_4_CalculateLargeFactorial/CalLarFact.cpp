#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> factRes;
void CalFact(int num) {
	int carry = 0;
	for (int i = 0; i < factRes.size(); i++)	{
		int digit = factRes[i] * num + carry;
		factRes[i] = digit % 10;
		carry = digit / 10;
	}
	while (carry != 0) {
		factRes.push_back(carry % 10);
		carry /= 10;
	}
}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)	{
		if (i == 1) {
			factRes.push_back(1);
		}
		else {
			CalFact(i);
		}
	}
	//	reverse(factRes.begin(), factRes.end());
	for (int i = factRes.size() - 1; i >= 0; i--)	{
		printf("%d", factRes[i]);
	}
	printf("\n");
	return 0;
}