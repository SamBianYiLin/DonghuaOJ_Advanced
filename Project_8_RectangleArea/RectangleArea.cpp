#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	double lx1, ly1, rx1, ry1;
	double lx2, ly2, rx2, ry2;
	double area = 0;
	scanf("%lf%lf%lf%lf", &lx1, &ly1, &rx1, &ry1);
	scanf("%lf%lf%lf%lf", &lx2, &ly2, &rx2, &ry2);
	if (lx1 == lx1 && ly1 == ly2) {
		if (rx1 == rx2 && ry1 == ry2) {
			area = (rx1 - lx1) * (ry1 - ly1);
		}
		
	}
	
	if ((lx2 > lx1 && lx2 < rx1) && (ly2 > ly1 && ly2 < ry1)) {
		if ((rx2 > rx1) && (ry2 > ry1)) {
			area = (rx1 - lx2) * (ry1 - ly2);
		}
		else if (lx2 < rx1 && ry2 > ry1) {
			area = (rx2 - lx2) * (ry1 - ly2);
		}
		else if (rx2 > rx1 && ry1 < ry1) {
			area = (rx1 - lx2) * (ry2 - ly1);
		}
		else {
			area = (rx2 - rx1) * (ry2 - ry1);
		}
	}
	if ((lx1 > lx2 && lx1 < rx2) && (ly1 > ly2 && ly1 < ry2)) {
		if (rx1 > rx2 && ry1 > ry2) {
			area = (rx2 - lx1) * (ry2 - ly1);
		}
		else if (rx1 > rx2 && ry1 > ry2) {
			area = (rx1 - lx1) * (ry2 - ly1);
		}
		else if (rx1 < rx2 && ry1 > ry2) {
			area = (lx2 - lx1) * (ry2 - ly1);
		}
		else {
			area = (rx1 - lx1) * (ry1 - ly1);
		}
	}
	printf("%.2lf\n", area);
	return 0;
}