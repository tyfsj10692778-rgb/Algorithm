#include<iostream>
using namespace std;

void solve()
{
	long long n,m; cin >> n >> m;
	if (n == m) cout << 0 << endl;
	else if ((n & m) == n || (n & m) == m) cout << 1 << endl;
	else cout << 2 << endl;
}
int main()
{
	int n; cin >> n;
	while (n --)
	{
		solve();
	}
	return 0;
}
