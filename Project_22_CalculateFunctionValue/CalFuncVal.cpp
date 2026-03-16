#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
//void GetDigit1And2Num(long long num,long long &num_counter) {
//	while (num > 0) {
//		if (num % 10 == 1 || num % 10 == 2) {
//			num_counter++;
//		}
//		num /= 10;
//	}
//}
int main() {
	char c[10000];
	scanf("%s", c);
	string n = c;
	long long counter = 0;
	int len = n.size();
	for (int i = 0; i < len; i++){
		long long high = 0, low = 0;
		int cur = n[i] - '0';
		for (int j = 0; j < i; j++)
			high =( high * 10 + (n[j] - '0'))%20123;
		for (int j = i + 1; j < len; j++)
			low = (low * 10 + (n[j] - '0')) % 20123;
		long long base = 1;
		for (int j = 0; j < len - i - 1; j++)	{
			base *= 10;
		}
		for (int d = 1; d <= 2; d++)	{
			if (cur > d) {
				counter += ((high + 1) * base) % 20123;
			}
			else if (cur == d) {
				counter += (high * base + low + 1) % 20123;
			}
			else {
				counter += (high * base) % 20123;
			}
		}
	}
	/*for (long long i = 1; i <= n; i++)	{
		long long num_counter = 0;
		GetDigit1And2Num(i, num_counter);
		counter = (counter + num_counter) % 20123;
	}*/
	printf("%lld\n", counter);
	return 0;
}