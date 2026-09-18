#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n --)
	{
		long long x , y; 
		cin >> x >> y;
		for(int i = 30; i >= 0; i --)
		{
			int bitex = (x >> i) & 1;
			int bitey = (y >> i) & 1;
			if (bitex != bitey)
			{
				long long n = (1LL << i);
				cout << n << endl;
				break;
			}
		}
	}
	return 0;
}
