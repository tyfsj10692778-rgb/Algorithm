#include<iostream>
#include<string>
#include<cmath>

using namespace std;

bool judge(int n)
{
	string s = to_string(n);
	int len = s.size();
	for(int i = 0; i < len / 2; i ++) if (s[i] != s[len - i - 1]) return false;
	return true;
}
int main()
{
	int n; cin >> n;
	int root = sqrt(n);
	
	if (root * root != n)
	{
		cout << "NO";
		return 0;
	}
	if (judge(root) && judge(n)) cout << "YES";
	else cout << "NO";
	return 0;
}
