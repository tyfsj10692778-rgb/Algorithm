#include<iostream>
#include<string>
using namespace std;

int main()
{	
	char ch; int balance = 0;
	
	while (cin >> ch && ch != '@')
	{
		if (ch == '(') balance ++;
		else if (ch == ')') balance --;
		if (balance < 0)
		{
			cout << "NO";
			return 0;
		}
	}
	if (balance != 0) cout << "NO";
	else cout << "YES";
	return 0;
}
