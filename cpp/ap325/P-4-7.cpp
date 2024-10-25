#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	int n;
	cin>>n;
	long long ans1=0;
	priority_queue<long long,vector<long long>,greater<long long>> a;
	for(int i=0,t;i<n;i++){
		cin>>t;
		a.push(t);
		ans1+=t;
	}
	long long ans2=0;
	while(1){
		long long t1=a.top();
		a.pop();
		if(a.empty()) break;
		long long t2=a.top();
		a.pop();
		ans2+=(t1+t2);
		a.push(t1+t2);
	}
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	return 0;
}