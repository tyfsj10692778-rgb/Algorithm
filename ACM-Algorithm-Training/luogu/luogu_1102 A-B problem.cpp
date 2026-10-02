#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
	long long n, c; cin >> n >> c;
	vector<long long> a(n);
	unordered_map<long long,long long> cnt;
	
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		cnt[a[i]] ++;
	}
	long long count = 0;
	
	for(int i = 0; i < n; i ++)
	{
		long long b = a[i];
		long long target_A = b + c;
		if (cnt.count(target_A)) count += cnt[target_A];
	}
	cout << count;
	return 0;
}
