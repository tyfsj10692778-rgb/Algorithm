#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a, b;
	cin >> a;
	cin.ignore();
	getline(cin, b);
	

	for(int i = 0; i < a.size(); i++) if (a[i] > 'a') a[i] -= 32;
	for(int i = 0; i < b.size(); i++) if (b[i] > 'a') b[i] -= 32;
	
	
	int  count = 0 , position = -1 , ans = -1 , num = 0;
	int length = a.size();
	
	b = ' ' + b + ' ';
	
	for(int i = 0; i < b.size(); i ++)
	{
		if(b[i] == ' ')
		{
			if (position != -1 && i - position - 1 == length)
			{
				num = 0;
				for(int j = position + 1; j < i; j++)if (a[j - (position + 1)] == b[j]) num ++;
				if (num == length)
				{
					count ++;
					if (ans == - 1) ans = position;
				}
			}
			position = i;
		}
	}
	if (count == 0) cout << -1;
	else cout << count << ' ' << ans;
	return 0;
}
