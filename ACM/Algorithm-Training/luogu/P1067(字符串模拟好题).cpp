#include<iostream>
#include<cmath>
using namespace std;
int a[105];

int  main()
{
	int n; cin >> n;
	bool frist = true;
	for(int i = n; i >= 0; i--) cin >> a[i];
	
	for(int i = n; i >= 0; i--)
	{
		if (a[i] == 0) continue;
		
		if (frist)
		{
			if (a[i] < 0) cout << '-';
			frist = false;
		}
		else
		{
			if (a[i] > 0) cout << "+" ;
			else cout << "-";
		}
		
		int absolote_value = abs (a[i]);
		if (absolote_value != 1 || i == 0) cout << absolote_value;
		
		if (i >= 2 && i <= n) cout << "x^" << i;
		else if (i == 1) cout << 'x';
	}
	if (frist) cout << '0';
	return 0;
}
