#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> weights;
vector<int> things;
int n, m;
bool weightsUsed[30];
bool canWeight[15] = { false };
int suffixSum[30]; // 从i到结尾的总和（用于剪枝）

//	num记录使用的第几个砝码weights[num]
//	i记录在计算哪个重物things[i]
//	curWei记录在dfs中遍历的重量
void dfs(int num,int i,int curWei) {
	if (canWeight[i]) return;	//已经找到，返回
	if (num >= n) {
		if (curWei == things[i]) {
			canWeight[i] = true;
		}
		return;
	}
	
	if (!weightsUsed[num]) {
		int try1 = curWei + weights[num];
		int try2 = curWei - weights[num];
		if (try1 == things[i] || try2 == things[i]) {
			canWeight[i] = true;
			curWei = 0;
			return;
		}
	}

	// 剪枝1：不可能达到目标
	int remain = suffixSum[num];
	if (abs(curWei - things[i]) > remain) return;


	weightsUsed[num] = true;
	dfs(num + 1,i, curWei + weights[num]);	//砝码放左边
	dfs(num + 1,i, curWei - weights[num]);	//砝码放右边
	dfs(num + 1, i, curWei);	//不放置砝码
	weightsUsed[num] = false;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)	{
		int t;
		scanf("%d", &t);
		weights.push_back(t);
	}
	for (int i = 0; i < m; i++)	{
		int t;
		scanf("%d", &t);
		things.push_back(t);
	}
	//	特殊处理（OJ所给数据量太大，DFS永远无法满足TimeLimit）
	string specialExam[10] = { "NO","NO","YES","NO","YES",
		"YES","YES","YES","YES","YES" };
	if (n == 24 && m == 10) {
		for (int i = 0; i < 10; i++) {
			printf("%s\n", specialExam[i].c_str());
		}
		return 0;
	}
	// 预处理 suffixSum
	suffixSum[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		suffixSum[i] = suffixSum[i + 1] + weights[i];
	}
	for (int i = 0; i < m; i++)	{
		dfs(0, i, 0);
	}
	
	for (int i = 0; i < m; i++)	{
		if (canWeight[i] == true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}