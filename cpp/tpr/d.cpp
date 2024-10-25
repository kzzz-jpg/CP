#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200500];
struct seg{
	int tr[800500];
	int n;
	seg(int N,int a[]):n(N){
		for(int i=0;i<n;i++) tr[i+n]=a[i];
		for(int i=n-1;i;i--) tr[i]=tr[i<<1]|tr[i<<1|1];
	}
	int qry(int l,int r){
		int ans=0;
		for(l+=n,r+=n;r>=l;r>>=1,l>>=1){
			if(l&1) ans|=tr[l++];
			if(!(r&1)) ans|=tr[r--];
		}
		return ans;
	}
};
signed main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	seg st=seg(n,a);
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<st.qry(l-1,r-1)<<'\n';
	}
}
