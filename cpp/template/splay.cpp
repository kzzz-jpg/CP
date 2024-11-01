#include<bits/stdc++.h>
using namespace std;
struct nd{
	int ch[2];
	int fa,sz,v,cnt;
} tr[200500];
int cnt,root;
void up(int x){
	tr[x].sz=tr[tr[x].ch[0]].sz+tr[tr[x].ch[1]].sz+tr[x].cnt;
}
bool ident(int x,int fa){
	return tr[fa].ch[1]==x;
}
void new_nd(int &node,int x,int fa){
	tr[node=++cnt].v=x;
	tr[node].cnt=1;
	tr[node].fa=fa;
	up(node);
}
void connect(int x,int fa,int k){
	tr[fa].ch[k]=x;
	tr[x].fa=fa;
}
void rotate(int x){
	int fa=tr[x].fa,ffa=tr[fa].fa,k=ident(x,fa);
	connect(tr[x].ch[k^1],fa,k);
	connect(x,ffa,ident(fa,ffa));
	connect(fa,x,k^1);
	up(fa);
	up(x);
}
void splay(int x){
	for(;tr[x].fa;rotate(x)){
		int fa=tr[x].fa;
		if(tr[fa].fa)
			rotate((ident(fa,tr[fa].fa)^ident(x,fa))?x:fa);
	}
	root=x;
}
void _insert(int &node,int x,int fa
