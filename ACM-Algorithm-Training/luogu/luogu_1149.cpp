#include<iostream>
#include<vector>
using namespace std;

int cost[]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int get_cost(int n)
{
	if (n == 0) return cost[0];
	int sum = 0;
	while(n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int n; 
	cin >> n;
	int ans = 0;
	for(int i = 0; i < 1000; i++)
	for(int j = 0; j < 1000; j++)
	{	
		int k = i + j;
		if (get_cost(i) + get_cost(j) + get_cost(k) == n - 4) ans ++; 
	}
	cout << ans;
	return 0;
}
