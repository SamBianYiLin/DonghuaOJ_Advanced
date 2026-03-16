#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<int> Primes;
bool IsPrime(int num) {
	for (int i = 2; i < num; i++){
		if (num % i == 0){
			return false;
		}
	}
	return true;
}
void PrintPrimeDiv(int num) {
	string res = to_string(num) + "=";
	for (int i = 0; i < Primes.size(); i++)	{
		while (num % Primes[i] == 0) {
			res = res + to_string(Primes[i]) + "*";
			num /= Primes[i];
		}
	}
	if (res[res.size() - 1] == '*') res.erase(res.size() - 1, 1);
	printf("%s\n", res.c_str());
}
int main() {
	int left, right;
	scanf("%d%d", &left, &right);
	for (int i = 2; i <= right; i++)	{
		if (IsPrime(i)) {
			Primes.push_back(i);
		}
	}
	for (int i = left; i <= right; i++){
		PrintPrimeDiv(i);
	}
}