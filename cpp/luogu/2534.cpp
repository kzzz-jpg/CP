#include<bits/stdc++.h>
using namespace std;
int a[17];
int ans=999,dd,n;
bool vs[17];
int ev(){
	int ret=0;
	for(int i=2;i<=n;i++) if(a[i]-a[i-1]!=1) ret++;
	return ret;
}
vector<int> aans;
void dfs(int stp){
	int e=ev();
	if(e==0){
		ans=min(stp,ans);
		for(auto xx:aans) cout<<xx<<' ';
		cout<<'\n';
		return;
	}
	if(stp+e>dd) return;
	for(int i=2;i<=n;i++){
		if(vs[i]) continue;
		aans.push_back(i);
		reverse(a+1,a+i+1);
		vs[i]=1;
		dfs(stp+1);
		vs[i]=0;
		reverse(a+1,a+1+i);
		aans.pop_back();
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> lsh(a+1,a+1+n);
	sort(lsh.begin(),lsh.end());
	lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
	for(int i=1;i<=n;i++) a[i]=lower_bound(lsh.begin(),lsh.end(),a[i])-lsh.begin()+1;
	for(dd=1;ans==999&&dd<=16;dfs(0),dd++);
	cout<<ans<<'\n';
}
