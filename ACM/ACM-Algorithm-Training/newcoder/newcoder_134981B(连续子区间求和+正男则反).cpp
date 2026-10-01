//组合数学好题。
//
#include<iostream>
#include<string>
using namespace std;

int main()
{
	long long n; cin >> n;
	string s; cin >> s;
	long long current_length = 1;
	long long bad_sum = 0;
	for(int i = 1; i < n; i ++)
	{
		if (s[i - 1] == s[i]) current_length ++;
		else
		{
			bad_sum += (current_length) * (current_length + 1) / 2;
			current_length = 1;
		}
	}
	bad_sum += (current_length) * (current_length + 1) / 2;
	long long ans = (n * (n + 1) / 2)- bad_sum;
	cout << ans;
	return 0;
}
