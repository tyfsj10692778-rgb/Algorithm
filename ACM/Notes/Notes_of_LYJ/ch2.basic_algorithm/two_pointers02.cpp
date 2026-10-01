/*
	题目大意：字符串本身或者删去一个字符后是否为回文串。
*/
#include<bits/stdc++.h>
using namespace std;

bool check(int l, int r, string s)
{
	while(l < r)
	{
		if(s[l] == s[r]) {l++; r--;}
		else return false;
	}
	return true;
}

bool is_real(string s)
{
	int i = 0, j = s.size() - 1;
	while(i < j)
	{
		if(s[i] == s[j]) {i++; j--;}
		else return (check(i + 1, j, s) || check(i, j - 1, s));
	}
	return true;
}
int main()
{
	string s; cin >> s;
	if(is_real(s)) cout << "yes";
	else cout << "no";
	return 0;
}

