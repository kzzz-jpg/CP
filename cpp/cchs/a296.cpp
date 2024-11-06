#include<bits/stdc++.h>
using namespace std;
int dis[505000];
void bfs(){
	queue<int> q;
	q.push(1);
	dis[1]=1;
	while(q.size()){
		auto tp=q.front();q.pop();
		if(tp+dis[tp]<=500500&&!dis[tp+dis[tp]]){
			q.push(tp+dis[tp]);
			dis[tp+dis[tp]]=dis[tp]+1;
		}
		if(tp+dis[tp]+1<=500500&&!dis[tp+dis[tp]+1]){
			q.push(tp+dis[tp]+1);
			dis[tp+dis[tp]+1]=dis[tp]+1;
		}
	}
}
signed main(){
	bfs();
	string s;
	while(cin>>s){
		if(s=="Rhombus"){
			vector<int> a(4);
			cin>>a[0]>>a[1]>>a[2]>>a[3];
			vector<int> d(4,999999);
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(j==i) continue;
					d[i]=min(d[i],abs(dis[a[i]]-dis[a[j]]));
				}
			}
			sort(d.begin(),d.end());
			if(d[0]==d[3]) cout<<"Yes\n";
			else cout<<"No\n";
		}
		if(s=="Regular_Triangle"){
			vector<int> a(3);
			cin>>a[0]>>a[1]>>a[2];
			vector<int> d(3,999999);
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(j==i) continue;
					d[i]=min(d[i],abs(dis[a[i]]-dis[a[j]]));
				}
			}
			sort(d.begin(),d.end());
			if(d[0]==d[2]) cout<<"Yes\n";
			else cout<<"No\n";
		}
		if(s=="Regular_Hexagon"){
			vector<int> a(6);
			cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
			vector<int> d(6,999999);
			for(int i=0;i<6;i++){
				for(int j=0;j<6;j++){
					if(j==i) continue;
					d[i]=min(d[i],abs(dis[a[i]]-dis[a[j]]));
				}
			}
			sort(d.begin(),d.end());
			if(d[0]==d[5]) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
}
