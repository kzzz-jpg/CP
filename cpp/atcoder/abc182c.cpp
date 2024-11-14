#include<bits/stdc++.h>
using namespace std;
string s;
int a[20];
int ans=9999999;
void dfs(int d,int sum){
	if(sum%3==0){
		if(d<s.size())
			ans=min(ans,d);
		return;
	}
	for(int i=0;i<s.size();i++){
		if(a[i]==-1) continue;
		int ori=a[i];
		sum-=a[i];
		a[i]=-1;
		dfs(d+1,sum);
		a[i]=ori;
		sum+=a[i];
	}
}
signed main(){
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++) a[i]=s[i]-'0',sum+=a[i];
	dfs(0,sum);
	if(ans==9999999) cout<<-1<<'\n';
	else cout<<ans<<'\n';
}
