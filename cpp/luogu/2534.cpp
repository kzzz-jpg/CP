#include<bits/stdc++.h>
using namespace std;
int a[17];
int ans=999,dd,n;
int ev(){
	int ret=0;
	for(int i=2;i<=n;i++) if(abs(a[i]-a[i-1])!=1) ret++;
	return ret;
}
vector<int> aans;
void dfs(int stp){
	int e=ev();
	if(e==0){
		ans=min(stp,ans);
		for(auto x:aans) cout<<x<<' ';
		cout<<'\n';
		return;
	}
	if(stp+e>dd) return;
	for(int i=2;i<=n;i++){
		reverse(a+1,a+i+1);
		aans.push_back(i);
		dfs(stp+1);
		aans.pop_back();
		reverse(a+1,a+1+i);
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
