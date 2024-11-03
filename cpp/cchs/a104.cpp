#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[300500],b[300500];
vector<int> lsh;
int fw[700000];
int n,ans;
void upd(int x){
	for(;x<700000;x+=x&-x){
		fw[x]+=1;
	}
}
int ask(int x){
	int ret=0;
	for(;x;x-=x&-x){
		ret+=fw[x];
	}
	return ret;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lsh.push_back(a[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]+=a[i];
		lsh.push_back(b[i]);
	}
	sort(lsh.begin(),lsh.end());
	lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
	for(int i=1;i<=n;i++) a[i]=lower_bound(lsh.begin(),lsh.end(),a[i])-lsh.begin()+1;
	for(int i=1;i<=n;i++) b[i]=lower_bound(lsh.begin(),lsh.end(),b[i])-lsh.begin()+1;
	for(int i=1;i<=n;i++){
		ans+=ask(b[i]-1);
		upd(a[i]);
	}
	cout<<ans<<'\n';
}
