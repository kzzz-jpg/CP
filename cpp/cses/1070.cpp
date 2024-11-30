#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
signed main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<1<<'\n';
		return 0;
	}else if(n<=3){
		cout<<"NO SOLUTION\n";
		return 0;
	}else if(n==4){
		cout<<"3 1 4 2\n";
		return 0;
	}else{
		for(int i=1;i<=n;i+=2){
			cout<<i<<" ";
		}
		for(int i=2;i<=n;i+=2){
			cout<<i<<" ";
		}
		cout<<'\n';
		return 0;
	}
}
