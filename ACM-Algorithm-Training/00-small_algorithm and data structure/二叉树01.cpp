/*
UVA 679 核心结论：满二叉树的左右子节点的编号是2k和2k+1
然后模拟。最后输出叶子的值 等价于每次由根节点编号更新出子节点的编号。
*/
#include<bits/stdc++.h>
using namespace std;
bool s[1 << 20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
	法一
	int n; cin >> n;
	while(n--){
		int d, i; cin >> d >> i;
		
		int k = 1;
		
		while(d--){
			if(i % 2) {k *= 2; i = (i + 1) / 2;}
			else {k = 2*k + 1; i /= 2;}
		}
		k /= 2;
		cout << k << "\n";
	}*/
	
	// 法二 模拟开关
	int n; cin >> n;
	
	while(n--){
		
		memset(s,false,sizeof s);
		int d,i; cin >> d >> i;
		int k , m = (1 << d) - 1;
		
		for(int j = 0; j < i; j++){
			k = 1;
			for(;;){
				s[k] = !s[k];
				k = s[k] ? 2*k : 2*k + 1;
				if(k > m) break;
			}
		}
		k /= 2;
		cout << k << "\n";
	}
	return 0;
}
