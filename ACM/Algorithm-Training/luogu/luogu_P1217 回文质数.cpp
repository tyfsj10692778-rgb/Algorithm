#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n)
{
	if (n < 2) return false;
	for(int i = 2; i <= n / i; i++) if (n % i == 0) return false;
	return true;
}

int main()
{
	int a, b; cin >> a >> b;
	
	if (b > 9999999) b = 9999999;
	
	if (a <= 5 && b >= 5) cout << 5 << "\n";
	if (a <= 7 && b >= 7) cout << 7 << "\n";
	if (a <= 11 && b >= 11) cout << 11 << "\n";
	
	for(int d1 = 1; d1 <= 9; d1 += 2)
	for(int d2 = 0; d2 <= 9; d2++)
	{
		int num = 100 * d1 + 10 * d2 + d1;
		if ((num >= a && num <= b) && isprime(num)) cout << num << "\n";
	}
	
	for(int d1 = 1; d1 <= 9; d1 += 2)
	for(int d2 = 0; d2 <= 9; d2++)
	for(int d3 = 0; d3 <= 9; d3++)
	{
		int num = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
		if ((num >= a && num <= b) && isprime(num)) cout << num << "\n";
	}
	
	for(int d1 = 1; d1 <= 9; d1 += 2)
	for(int d2 = 0; d2 <= 9; d2++)
	for(int d3 = 0; d3 <= 9; d3++)
	for(int d4 = 0; d4 <= 9; d4++)
		{
			if (1000000 * d1 > b) return 0;
			int num = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
			if ((num >= a && num <= b) && isprime(num)) cout << num << "\n";
		}
	
	return 0;
}
