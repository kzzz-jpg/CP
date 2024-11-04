#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y,z;
	node(int X=0,int Y=0,int Z=0):x(X),y(Y),z(Z){}
	bool operator < (node o) const{
		if(x==o.x){
			if(y==o.y) return z<o.z;
			return y<o.y;
		}
		return x<o.x;
	}
} q[200500];
int n;
int fw[600500];
void upd(int x,int v){
	for(;x<=60000;x+=x&-x) fw[x]=min(fw[x],v);
}
int ask(int x){
	int ret=1e15;
	for(;x;x-=x&-x) ret=min(ret,fw[x]);
	return ret;
}
signed main(){
	for(int i=0;i<=600000;i++) fw[i]=1e15;
	cin>>n;
	int x,y,z;
	vector<int> lsh;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>z;
		lsh.push_back(x),lsh.push_back(y),lsh.push_back(z);
		if(x>y) swap(x,y);
		if(y>z) swap(y,z);
		if(x>y) swap(x,y);
		q[i]=node(x,y,z);
	}
	sort(lsh.begin(),lsh.end());
	lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
	for(int i=1;i<=n;i++){
		q[i].x=lower_bound(lsh.begin(),lsh.end(),q[i].x)-lsh.begin()+1;
		q[i].y=lower_bound(lsh.begin(),lsh.end(),q[i].y)-lsh.begin()+1;
		q[i].z=lower_bound(lsh.begin(),lsh.end(),q[i].z)-lsh.begin()+1;
	}
	sort(q+1,q+1+n);
	for(int i=1,j=1;i<=n;i=j){
		while(q[i].x==q[j].x) j++;
		for(int k=i;k<j;k++){
			if(ask(q[k].y-1)<q[k].z){
				cout<<"Yes\n";
				return 0;
			}
		}
		for(int k=i;k<j;k++) upd(q[k].y,q[i].z);
	}
	cout<<"No\n";
}
