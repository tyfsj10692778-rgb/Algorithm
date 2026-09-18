#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	
	string a, b; 
	while (cin >> b){a += b;}
	int count_A = 0, count_B = 0;
	
	int len = a.size();
	for(int i = 0; i < len; i ++)
	{	
		if (a[i] == 'E') break;
		if (a[i] == 'W') count_A ++;
		else if (a[i] == 'L') count_B ++;
		if ((count_A >= 11 || count_B >= 11) && abs(count_A - count_B) >= 2)
		{	
			cout << count_A << ':' << count_B << endl;
			count_A = count_B = 0;
		}
	}
	cout << count_A << ':' << count_B << endl;
	cout << endl;
	count_A = 0, count_B = 0;
	for(int i = 0; i < len; i ++)
	{	
		if (a[i] == 'E') break;
		if (a[i] == 'W') count_A ++;
		else if (a[i] == 'L') count_B ++;
		if ((count_A >= 21 || count_B >= 21) && abs(count_A - count_B) >= 2)
		{	
			cout << count_A << ':' << count_B << endl;
			count_A = count_B = 0;
		}
	}
	cout << count_A << ':' << count_B << endl;
	return 0;
}
