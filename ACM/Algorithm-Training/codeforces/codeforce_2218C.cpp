#include<iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	while (n --)
	{
		int m; cin >> m;
		int count = 0;
		for(int i = 1; i <= m; i++) 
		{
			cout << i << ' ' << 3 * m - (i - 1) - count << ' ' << 3 * m - i - count << ' ';
			count ++;
		}
		cout << endl;
	}
	return 0;
}
