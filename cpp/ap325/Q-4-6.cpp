#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<long long,long long> a,pair<long long,long long> b){
	return a.first*b.second<b.first*a.second;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	int n;
	cin>>n;
	vector<pair<long long,long long>> w(n);
	for(int i=0;i<n;i++){
		cin>>w[i].first;
	}
	for(int i=0;i<n;i++){
		cin>>w[i].second;
	}
	sort(w.begin(),w.end(),cmp);
	long long now=0;
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=now*w[i].second;
		now+=w[i].first;
	}
	cout<<ans<<endl;
	return 0;
}