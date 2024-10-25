#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
	int n;
	cin>>n;
	vector<int> a,b;
	for(int i=0;i<n;i++) cin>>a[i],b[i]=a[i];
	sort(a.begin(),a.end());
	int sum=0;
