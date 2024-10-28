#include<bits/stdc++.h>
using namespace std;
int hd[200500],nxt[400500],to[400500];
bool vs[200500];
int cnt=1,n,m,s;
void addE(int a,int b){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	hd[a]=cnt++;
}
signed main(){
	cin>>n>>m>>s;
	int x,y;
	while(m--){
		cin>>x>>y;
		addE(x,y),addE(y,x);
	}
	vs[s]=1;
	queue<int> q;
	q.push(s);
	while(q.size()){
		auto tp=q.front();q.pop();
		bool chk=1;
		for(int e=hd[tp];e;e=nxt[e]){
			if(!vs[to[e]]){
				chk=0;
				vs[to[e]]=1;
				q.push(to[e]);
			}
		}
		if(chk) cout<<tp<<'\n';
	}
}
