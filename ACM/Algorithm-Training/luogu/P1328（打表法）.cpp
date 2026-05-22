#include<iostream>
using namespace std;
int a[210], b[210];

int score[5][5]=
{
	{0,0,1,1,0},
	{1,0,0,1,0},
	{0,1,0,0,1},
	{0,0,1,0,1},
	{1,1,0,0,0}
};
int main()
{
	int n, na, nb; cin >> n >> na >> nb;
	for(int i = 0; i < na; i ++) cin >> a[i];
	for(int i = 0; i < nb; i ++) cin >> b[i];
	
	int sum_A= 0, sum_B = 0;
	for(int i = 0; i < n; i ++)
	{
		sum_A += score[a[i % na]][b[i % nb]];
		sum_B += score[b[i % nb]][a[i % na]];
	}
	cout << sum_A << ' ' << sum_B;
	return 0;
}
