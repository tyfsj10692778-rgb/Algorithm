#include<iostream>
#include<set>
using namespace std;

int main()
{
	int n; cin >> n;
	set<int>s;
	for(int i = 0; i < n; i ++)
	{
		int x; cin >> x;
		s.insert(x);
	}
	cout << s.size() << "\n";
	for(int x : s) cout << x << ' ';
	return 0;
}
