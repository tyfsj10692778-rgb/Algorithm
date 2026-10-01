#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	long long n, k; cin >> n >> k;
	long long min_step = abs(k);
	
	for(int i = 0; i < n; i ++)
	{
		long long x, y; cin >> x >> y;
		
		long long current_step = abs(x) + abs(y - k);
		
		min_step = min(min_step, current_step);
	}
	cout << min_step;
	return 0;
}
