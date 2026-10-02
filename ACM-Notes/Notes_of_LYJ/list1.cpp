/*
to understand how to built a list.
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node * next;
};
int main()
{
	int n,m;
	cin >> n >> m;
	// key code
	node * head, * p, * now, * prev;
	head = new node;head -> data = 1;head -> next = NULL;
	now = head;
	// the moving ptr "now" links every points.
	
	for(int i = 2; i <= n; i++)
	{
		p = new node; p -> data = i; p -> next = NULL;
		now -> next = p;
		now = p;
	}
	now -> next = head;
	
	// for this problem,we need let prev -> next repalaces now
	// then delete it.
	now = head, prev = head;
	while((n--) > 1)
	{
		for(int i = 1; i < m; i++)
		{
			prev = now;
			now = now -> next;
		}
		cout << now -> data << " ";
		prev -> next = now -> next;
		delete now;
		now = prev -> next;
	}
	cout << now -> data;
	delete now;
	return 0;
}
