#include<iostream>
#include<string>
using namespace std;

struct str
{
	int face;
	string s;
}a[100005];

int main()
{
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i ++) cin >> a[i].face >> a[i].s;
	
	int now = 0;
	
	for(int i = 0; i < m ; i ++)
	{
		int dir, step; cin >> dir >> step;
		if (dir == a[now].face) now = (now - step + n) % n;
		else now = (now + step) % n;
	}
	cout << a[now].s;
	return 0;
}
