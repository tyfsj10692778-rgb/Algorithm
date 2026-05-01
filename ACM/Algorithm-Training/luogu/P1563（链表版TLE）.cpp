#include<iostream>
#include<string>
using namespace std;

struct str
{	
	int face;
	string s;
	str* next;
	str* prev;
	str(int f,string c): face(f),s(c),next(NULL){}
};
int main()
{
	int n, m; cin >> n >> m;
	str* head = NULL;
	str* last = NULL;
	for(int i = 0; i < n; i ++)
	{
		int k; string name;
		cin >> k >> name;
		str* now = new str(k, name);
		
		if (head == NULL)
		{
			head = now;
			last = now;
		}
		else
		{
			last -> next = now;
			now -> prev = last;
			last = now;
		}
	}
	last -> next = head;
	head -> prev = last;
	
	str* now = head;
	for(int i = 0; i < m; i ++)
	{
		int a, b; cin >> a >> b;
		
		bool move_next = (a == now -> face);
		
		for(int j = 0; j < b; j ++)
		{
			if (move_next) now = now -> prev;
			else now = now -> next;
		}
	}
	cout << now -> s;
	return 0;
}
