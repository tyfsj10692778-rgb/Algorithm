#include<iostream>
using namespace std;
int main()
{
	int i = 1;
	int b = i++;
	cout << b << " " << i;
	cout << "\n";
	b = ++i;
	cout << b << " " << i;
}
