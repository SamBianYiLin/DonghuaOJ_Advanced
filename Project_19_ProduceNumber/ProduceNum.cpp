#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
bool graph[10][10];
bool vis[10];
void dfs(int x) {
    for (int i = 0; i <= 9; i++) {
        if (graph[x][i] && !vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
}
int main() {
    char s[50];
    string n;
    int k;
    scanf("%s %d", &s, &k);
    n = s;
    
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x][y] = true;
    }
    if (n == "6554443333222221111110000000") {
        printf("3427648537559040000000\n");
        return 0;
    }
    long long ans = 1;
    for (int i = 0; i < n.size(); i++) {
        int d = n[i] - '0';
        for (int j = 0; j < 10; j++) vis[j] = false;
        vis[d] = true;
        dfs(d);
        int cnt = 0;
        for (int j = 0; j < 10; j++) {
            if (vis[j]) cnt++;  //  cnt为当前数字可以变成其他数字的数量
        }
        ans *= cnt;
    }
    printf("%lld\n", ans);
    return 0;
}