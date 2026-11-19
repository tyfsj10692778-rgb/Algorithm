#include<bits/stdc++.h>
using namespace std;
const int N = 1E3 + 10;
int pre[N],in[N],pos[N];
int k;
struct node{
	int value;
	node * l, *r;
	node(int value = 0, node * l = NULL, node * r = NULL) : value(value),l(l),r(r){}
};
void buildtree(int l, int r, int & t, node * & root){
	int flag = -1;
	for(int i = l; i <= r; i++)
		if(in[i] == pre[t]){
			flag = i; break;
		}
	if(flag == -1) return;
	root = new node(in[flag]);
	t++;
	if(flag > l) buildtree(l, flag - 1, t, root -> l);
	if(flag < r) buildtree(flag + 1, r, t, root -> r);
}
void preorder(node * root){
	if(root != NULL){
		pos[k++] = root -> value;
		preorder(root -> l);
		preorder(root -> r);
	}
}
void inorder(node * root){
	if(root != NULL){
		inorder(root -> l);
		pos[k++] = root -> value;
		inorder(root -> r);
	}
}
void postorder(node * root){
	if(root != NULL){
		postorder(root -> l);
		postorder(root -> r);
		pos[k++] = root -> value;
	}
}
void remove_tree(node * root){
	if(root == NULL) return;
	remove_tree(root -> l);
	remove_tree(root -> r);
	delete root;
}

int main(){
	
	int n;
	while(~scanf("%d",&n)){
		for(int i = 1; i <= n; i++) cin >> pre[i];
		for(int i = 1; i <= n; i++) cin >> in[i];
		node * root = NULL;
		int t = 1;
		buildtree(1,n,t,root);
		k = 0;
		postorder(root);
		for(int i = 0; i < k; i ++) cout << pos[i] << (i == k - 1 ? '\n' : ' ');
		remove_tree(root);
	}
	return 0;
}
