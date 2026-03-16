#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int v1, v2, t, s, l;
	scanf("%d%d%d%d%d", &v1, &v2, &t, &s, &l);
	int rabDis = 0, turDis = 0;
	bool rabRes = false;	//	兔子是否在休息
	int resTime = 0;	//	兔子开始休息的时间	
	//	最慢速度为1，需要l秒
	for (int i = 1; i <= l; i++) {
		turDis += v2;
		if (!rabRes)	rabDis += v1;
		if ((rabDis == turDis) && (rabDis == l)) {
			printf("D\n");
			printf("%d\n", i);
			return 0;
		}
		if (rabDis == l || turDis == l) {
			if (rabDis == l) {
				printf("R\n");
				printf("%d\n", i);
				return 0;
			}
			else if (turDis == l) {
				printf("T\n");
				printf("%d\n", i);
				return 0;
			}
		}
		if (!rabRes && rabDis - turDis >= t) {
			rabRes = true;
			resTime = i;
		}
		if (rabRes && i - resTime == s) {
			rabRes = false;
		}
	}
	return 0;
}