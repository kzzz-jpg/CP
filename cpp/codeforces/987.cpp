#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;
	cin>>n;
	vector<int> v;
	int t;
	for(int i=0;i<n;i++){
		cin>>t;
		auto it=upper_bound(v.begin(),v.end(),t);
		if(it==v.end()) v.push_back(t);
		else *it=t;
	}
	cout<<(n-v.size())<<'\n';
}
void solve2(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		if(pq.size()&&pq.top()-v[i]>1){
			cout<<"No\n";
			return;
		}
		pq.push(v[i]);
	}
	cout<<"Yes\n";
}
void solve3(){
	int n;
	cin>>n;
	if(n<27&&(n&1)) {cout<<-1<<'\n';return;}
	if(!(n&1)){
		for(int i=0;i<n;i+=2) cout<<i+1<<' '<<i+1<<' ';
		cout<<'\n';
		return;
	}
	vector<int> a(n+1);
	a[1]=a[10]=a[26]=1;
	a[27]=a[23]=2;
	int cnt=3;
	for(int i=2;i<=n;i++){
		if(a[i]||a[i+1]) continue;
		a[i]=a[i+1]=cnt++;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
}
int fw[500500];
void upd(int x,int v){
	for(;x<500500;x+=(x&-x)){
		fw[x]=max(fw[x],v);
	}
}
int qry(int x){
	int ret=0;
	for(;x;x-=(x&-x)){
		ret=max(ret,fw[x]);
	}
	return ret;
}
int n=500000;
int fa[500500],sz[500500],a[500500],ans[500500],mx[500500],pos[500500];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void cb(int aa,int b){
	aa=find(aa),b=find(b);
	if(aa==b) return;
	if(sz[aa]>sz[b]) swap(aa,b);
	fa[aa]=b;
	pos[b]=max(pos[aa],pos[b]);
	sz[b]+=sz[aa];
}
void solve4(){
	for(int i=0;i<=n;i++) a[i]=0,mx[i]=0,fw[i]=0,sz[i]=1,pos[i]=fa[i]=i;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[mx[i-1]]>a[i]) mx[i]=mx[i-1];
		else mx[i]=i;
	}
	for(int i=n;i;i--){
		cb(i,max(qry(a[i]-1),i));
		cb(i,mx[i]);
		upd(a[i],i);
	}
	for(int i=1;i<=n;i++){
		cout<<a[mx[pos[find(i)]]]<<' ';
	}
	cout<<'\n';
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve4();
}
