//	本质为 拓扑排序 ，如果有环，则No answer
//	找到入度indree为0的点，即为最高的
//	A<B ==> A->B存在有向边
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	vector<vector<int>> graph(26, vector<int>(26, 0));
	vector<int> indegree(26, 0);
	vector<bool> exist(26, false);	//士兵是否出现过，出现过就需要参与排序
	char c[10] = { 0 };
	while (scanf("%s", c) != EOF) {
		int a = c[0] - 'A';
		int b = c[2] - 'A';
		if (graph[a][b] == 0) {
			graph[a][b] = 1;
			indegree[b]++;
		}
		exist[a] = true;
		exist[b] = true;
	}
	string ans = "";
	for (int topoSort = 0; topoSort < 26; topoSort++)	{
		for (int i = 0; i < 26; i++)	{
			if (exist[i] && indegree[i] == 0) {
				ans += i + 'A';
				indegree[i] = -1;
				for (int j = 0; j < 26; j++) {
					if (graph[i][j] != 0) {
						indegree[j]--;
					}
				}
				break;
			}			
		}
	}
	int counter = 0;
	for (int i = 0; i < 26; i++)	{
		if (exist[i]) counter++;
	}
	if (ans.size() != counter) {
		printf("No Answer!\n");
	}
	else {
		printf("%s", ans.c_str());
	}
	return 0;
}