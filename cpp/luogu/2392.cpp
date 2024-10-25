#include<bits/stdc++.h>
using namespace std;
int t[4];
bitset<1200> v[4];
int l,r,tmp,sum;
int ans;
signed main(){
	for(int i=0;i<4;i++) cin>>t[i];
	for(int i=0;i<4;i++){
		sum=l=r=0;
		v[i][0]=1;
		for(int j=1;j<=t[i];j++){
			cin>>tmp;
			sum+=tmp;
			v[i]|=v[i]<<tmp;
		}
		for(int j=sum/2;j>=0;j--){
			if(v[i][j]) {ans+=sum-j;break;}
		}
	}
	cout<<ans<<'\n';
}
