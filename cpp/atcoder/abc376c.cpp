#include<bits/stdc++.h>
using namespace std;
int a[200500],b[200550];
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+n);
	for(int i=1;i<=n-1;i++) {
		if(a[i]>b[i]) {
			cout<<-1<<'\n';
			return 0;
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i]>b[i-1]){
			cout<<a[i]<<'\n';
			return 0;
		}
	}
}

