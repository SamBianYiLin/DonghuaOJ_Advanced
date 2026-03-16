#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) > 0) {
		char pic[27][27] = { 0 };
		int counter = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < m; j++) {
				pic[i][j] = 'A' + counter;
				counter++;
			}
			counter = 0;
		}
		counter = 0;
		for (int i = 0; i < m; i++) {
			for (int j = i; j < n; j++) {
				pic[j][i] = 'A' + counter;
				counter++;
			}
			counter = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (pic[i][j] == '\0') {
					printf(" ");
				}
				else printf("%c", pic[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}