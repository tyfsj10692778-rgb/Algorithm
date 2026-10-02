#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
	string s; cin >> s;
	set<char>characters;
	for(char x : s) characters.insert(x);
	if (characters.size() == 2) cout << "Yes";
	else cout << "No";
	return 0;
	
}
