#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	int n;
	cin>>n;
	vector<int> deg(n+1,0);
	vector<vector<int>> g(n+1);
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		deg[i]+=num;
		for(int j=0;j<num;j++){
			int r;
			cin>>r;
			g[r].push_back(i);
		}
	}
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=1;i<=n;i++){
		if(deg[i]==0) pq.push(i);
	}
	int space=0;
	while(!pq.empty()){
		int tp=pq.top();pq.pop();
		space++;
		cout<<tp;
		if(space<n) cout<<" ";
		for(auto x:g[tp]) {
			deg[x]--;
			if(deg[x]==0) pq.push(x);
		}
	}
	return 0;
}