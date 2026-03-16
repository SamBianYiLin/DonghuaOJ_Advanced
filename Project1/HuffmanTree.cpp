#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int> pq;
	int totalCost = 0;
	for (int i = 0; i < n; i++)	{
		int t;
		scanf("%d", &t);
		pq.push(-1 * t);	//	相反数最大，t最小，实现小根堆
	}
	while (pq.size() > 1) {
		int leaf1 = pq.top() * (-1);
		pq.pop();
		int leaf2 = pq.top() * (-1);
		pq.pop();
		pq.push((leaf1 + leaf2) * (-1));
		totalCost += (leaf1 + leaf2) * (-1);
	}
	printf("%d\n", totalCost * (-1));
	return 0;
}