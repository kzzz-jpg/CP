#include<bits/stdc++.h>
using namespace std;
string a,b,c;
priority_queue<char> pq;
signed main(){
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	for(auto x:c){
		if(x<='9'&&x>='0'){
			pq.push(x);
		}
	}
	for(int i=0;i<a.size();i++){
		if(i<a.size()&&a[i]=='?'){
			a[i]=pq.top();
			pq.pop();
		}
		if(i<b.size()&&b[i]=='?'){
			b[i]=pq.top();
			pq.pop();
		}
	}
	int pre=0;
	for(int i=a.size()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if(a[i]>'9') a[i-1]++,a[i]-=10;
	};
	cout<<a<<'\n';
}
