#include<bits/stdc++.h>
using namespace std;
int n,q;
inline int mv(int x){
	if(x<=0) return x+n;
	if(x>n) return x-n;
	return x;
}
int t,l,r,ans;
char h;
signed main(){
	cin>>n>>q;
	l=1,r=2;
	while(q--){
		cin>>h>>t;
		if(h=='L'){
			int tmp=l,tmpans=0;
			while(l!=t){
				l=mv(l-1);
				tmpans++;
				if(l==r) {
					l=tmp,tmpans=0;
					break;
				}
			}
			while(l!=t){
				l=mv(l+1);
				tmpans++;
			}
			ans+=tmpans;
		}else{
			int tmpr=r,tmpans=0;
			while(r!=t){
				r=mv(r+1);
				tmpans++;
				if(l==r){
				       	r=tmpr,tmpans=0;
					break;
				}
			}
			while(r!=t){
				r=mv(r-1);
				tmpans++;
			}
			ans+=tmpans;
		}
	}
	cout<<ans<<'\n';
}

