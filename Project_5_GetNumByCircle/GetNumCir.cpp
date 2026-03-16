#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int row, col;
	scanf("%d%d", &row, &col);
	vector<vector<int>> matrix;
	matrix.resize(row, vector<int>(col));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int t;
			scanf("%d", &t);
			matrix[i][j] = t;
		}
	}
	vector<int> line;
	int up = 0, down = row - 1;
	int left = 0, right = col - 1;
	while (left <= right && up <= down) {
		for (int t_row = up; t_row <= down; t_row++)
		{
			line.push_back(matrix[t_row][left]);
		}
		left++;
		for (int t_col = left; t_col <= right; t_col++)
		{
			line.push_back(matrix[down][t_col]);
		}
		down--;
		for (int t_row = down; t_row >= up; t_row--)
		{
			line.push_back(matrix[t_row][right]);
		}
		right--;
		for (int t_col = right; t_col >= left; t_col--)
		{
			line.push_back(matrix[up][t_col]);
		}
		up++;
		if (line.size() >= row * col) {
			break;
		}
	}
	for (int i = 0; i < row * col; i++)
	{
		if (i == 0) {
			printf("%d", line[i]);
		}
		else printf(" %d", line[i]);
	}
	return 0;
}