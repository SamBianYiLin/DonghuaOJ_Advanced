#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<vector<int>> matrix;
vector<vector<int>> resultMatrix;
int n;
int MatrixMulti(int row,int column, vector<vector<int>> tempResultMatrix) {
	vector<int> line;
	vector<int> col;
	for (int eachCol = 0; eachCol < n; eachCol++)
	{
		line.push_back(matrix[row][eachCol]);
	}
	for (int eachRow = 0; eachRow < n; eachRow++)
	{
		col.push_back(tempResultMatrix[eachRow][column]);
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += line[i] * col[i];
	}
	return sum;
}
int main() {
	int m;
	scanf("%d %d", &n, &m);
	matrix.resize(n, vector<int>(n));
	//	读入n阶矩阵matrix
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++)	{
			scanf("%d", &matrix[i][j]);
		}
	}
	resultMatrix = matrix;
	if (m == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == n - 1) {
					printf("%d", i == j ? 1 : 0);
				}
				else {
					printf("%d ", i == j ? 1 : 0);
				}
			}
			printf("\n");
		}
		return 0;
	}
	for (int pow = 0; pow < m - 1; pow++) {
		vector<vector<int>> tempResultMatrix = resultMatrix;
		for (int i = 0; i < n; i++)	{
			for (int j = 0; j < n; j++)	{
				resultMatrix[i][j] = MatrixMulti(i, j, tempResultMatrix);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1) {
				printf("%d", resultMatrix[i][j]);
			}
			else {
				printf("%d ", resultMatrix[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}