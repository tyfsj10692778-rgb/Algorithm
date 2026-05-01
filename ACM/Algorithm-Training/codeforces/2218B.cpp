#include<iostream>
using namespace std;

const int N = 100010;
int q[N];

void quick_sort(int q[], int l, int r)
{
	if (l >= r) return;
	
	int x = q[ l + r >> 1],  i = l - 1,j = r + 1;
	while (i < j)
	{
		do i ++; while (q[i] < x);
		do j --; while (q[j] > x);
		if (i < j) swap (q[i], q[j]);
	}
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}
int main ()
{	
	int n; cin >> n;
	while (n --)
	{
		for(int i = 0; i < 7; i++) cin >> q[i];
	
	quick_sort(q, 0, 6);
	
	int sum = 0;
		
	for(int i = 0; i < 7; i++) sum += q[i];
		
	cout << 2 * q[6] - sum  << endl;
	}
	
	return 0;
} 
