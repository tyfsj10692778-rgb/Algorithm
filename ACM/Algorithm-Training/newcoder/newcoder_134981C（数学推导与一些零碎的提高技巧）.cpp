#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <numeric>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<long long>a(n);
	for(auto &v : a) cin >> v;
	
	string s; cin >> s;
	
	long long sum = accumulate(a.begin(),a.end(),0ll);
	long long sum_red = 0, num_red = 0;
	for(int  i = 0 ; i < n; i ++) 
	if (s[i] == '0') 
	{
		sum_red += a[i];
		num_red ++;
	}
	if (num_red * sum % n) return cout << "-1" << endl , 0;
	
	long long target_red = num_red * sum / n;
	cout << abs (sum_red - target_red);
	return 0;
}
