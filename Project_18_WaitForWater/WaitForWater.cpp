#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int main() {
	int n, r;
	scanf("%d%d", &n, &r);
	priority_queue<int> Time;
	int timeSum = 0;
	for (int i = 0; i < n; i++){
		int t;
		scanf("%d", &t);
		Time.push(-1 * t);
		timeSum += t;
	}
	vector<int> faucet(r);
	int totalTime = 0;
	int currentTime = 0;
	while (timeSum > 0) {
		int faucetUse = 0;
		//	给水龙头分配人
		for (int i = 0; i < r; i++)
		{		
			if (faucet[i] == 0 && !Time.empty()) {
				faucet[i] =-1 * Time.top();
				Time.pop();
			}
		}
		//	是否水龙头都空了
		bool empty = true;
		for (int i = 0; i < r; i++)	{
			if (faucet[i] > 0) {
				faucet[i]--;
				empty = false;
				if (faucet[i] == 0) {
					totalTime += currentTime + 1;
				}
			}
		}
		if (empty && Time.empty()) {
			break;
		}
		else {
			currentTime++;
		}
	}
	printf("%d\n", totalTime);
	return 0;
}