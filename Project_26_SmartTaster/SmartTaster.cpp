//	The following codes use DFS to tranverse all situations
// but the time complexity was so high 
// it cannot pass OJ

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<vector>
//#include<queue>
//using namespace std;
//int maxTasty = 0;	//	最大“爽”的次数
//vector<int> yummy;	//	美味度评分vector
//int n;	//	美味度维度
//int curTasty = 0;	//	当前最大“爽”的次数
//bool isVisited[800] = { false };	//	是否访问过该美味度	
//void dfs(int cur, int curYummy) {
//	curTasty++;	//	吃掉当前食物
//	if (curTasty > maxTasty) {
//		maxTasty = curTasty;
//	}
//	isVisited[cur] = true;
//	for (int i = 1; i < n - cur; i++) {
//		if (yummy[cur + i] > curYummy) {
//			dfs(cur + i,yummy[cur + i]);
//		}
//	}
//	isVisited[cur] = false;
//	curTasty--;	//	释放条件
//}
//int main() {	
//	scanf("%d", &n);	
//	for (int i = 0; i < n; i++)	{
//		int t; scanf("%d", &t);
//		yummy.push_back(t);
//	}
//
//	//	Start taste foods
//	/*for (int i = 0; i < n; i++)	{
//		int current = yummy[i];
//		int curMaxTaste = 0;
//		for (int j = i; j < n; j++)	{
//			if (yummy[j] > current) {
//				curMaxTaste++;
//				current = yummy[i];
//			}
//		}
//		if (curMaxTaste > maxTasty) {
//			maxTasty = curMaxTaste;
//		}
//	}*/
//	dfs(0,yummy[0]);
//	printf("%d\n", maxTasty);
//	return 0;
//}

//	The following codes use LIS to tranverse
//  LIS(Longest Increasing Subsequence)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> yummy(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &yummy[i]);
    //  Initialize dp vector
    //  dp[i] = 以 i 结尾的最长递增子序列长度
    vector<int> dp(n, 1);
    int maxTasty = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (yummy[i] > yummy[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxTasty = max(maxTasty, dp[i]);
    }
    printf("%d\n", maxTasty);
}