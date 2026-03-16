#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> trap(100);
bool visited[50] = { false };
int n,counter = 0;
void dfs(int pos) {
	if (pos == n) {
		counter++;
		return;
	}
	if (pos == trap[pos] || pos > n) {
		return;
	}
	visited[pos] = true;
	dfs(pos + 1);
	dfs(pos + 2);
	visited[pos] = false;
}
int main() {
	//	n为目的地，m为陷阱个数
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < 100; i++){
		trap[i] = -1;
	}
	//	读取陷阱位置
	for (int i = 0; i < m; i++)	{
		int t;
		scanf("%d", &t);
		trap[t] = t;
	}
	dfs(1);
	printf("%d\n", counter);
	return 0;
}