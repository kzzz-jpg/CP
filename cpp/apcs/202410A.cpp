#include<bits/stdc++.h>
using namespace std;
int a[11];
int n,w1,w2,h1,h2,nw,ans;
int main(){
	cin>>n>>w1>>w2>>h1>>h2;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int chg=0,nchg=0;
		if(nw<h1){
			if(a[i]>=w1*w1*(h1-nw)){
				nchg+=h1-nw;
				a[i]-=w1*w1*(h1-nw);
			}else{
				nchg+=a[i]/(w1*w1);
				a[i]-=a[i]/(w1*w1);
			}
			nw+=nchg;
			chg+=nchg;
		}
		nchg=0;
		if(nw<h1+h2&&nw>=h1){
			if(a[i]>=w2*w2*(h2-(nw-h1))){
				nchg+=h2-(nw-h1);
				a[i]-=w2*w2*(h2-(nw-h1));
			}else{
				nchg+=a[i]/(w2*w2);
				a[i]-=a[i]/(w2*w2);
			}
			nw+=nchg;
			chg+=nchg;
		}
		ans=max(ans,chg);
		if(nw>=h1+h2) break;
	}
	cout<<ans<<'\n';
}
