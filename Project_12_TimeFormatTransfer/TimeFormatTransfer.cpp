#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int time;
	scanf("%d", &time);
	int hour = time / 3600;
	int removeHour = time - hour * 3600;
	int minute = removeHour / 60;
	int second = removeHour - minute * 60;
	printf("%d:%d:%d\n", hour, minute, second);
	return 0;
}