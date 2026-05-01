#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a; cin >> a;
	int count = 0 , num = 1;
	for(int i = 0; i < 12; i ++) if (a[i] != '-')
	{
		count += (a[i] - '0') * num;
		num ++;
	}
	count %= 11;
	
	if (count == 10 && a[12] == 'X') cout << "Right";
	else if (count == a[12] - '0') cout << "Right";
	else 
	{
		for(int i = 0; i < 12; i++) cout << a[i];
		if (count == 10) cout << 'X';
		else cout << count;
	}
	return 0;
}
