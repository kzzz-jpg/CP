#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[11][11][20];
int solve(int fst,int num,int len,int ofs,bool fr,int ls){
	if(len==0) return ls!=-1?1:0;
	int ans=0;
	int cur=(num/ofs)%10;
	if(ls==-1) ans+=solve(fst,num,len-1,ofs/10,true,-1);
	if(fr){
		for(int i=ls==-1?1:0;i<fst;i++){
            if(dp[fst][i][len]!=-1) ans+=dp[fst][i][len];
			else ans+=dp[fst][i][len]=solve(ls==-1?i:fst,num,len-1,ofs/10,true,i);
		}
	}else{
		for(int i=ls==-1?1:0;i<=min(cur,fst-1);i++){
			ans+=solve(ls==-1?i:fst,num,len-1,ofs/10,i<cur,i);
		}
	}
	return ans;
}
signed main(){
    for(int a=0;a<11;a++) for(int e=0;e<11;e++) for(int c=0;c<20;c++)   dp[a][e][c]=-1;
    int l,r;
	cin>>l>>r;
    l--;
	int llen=1,lofs=1,rofs=1,rlen=1;
	while(10*lofs<=l){
		lofs*=10;
		llen++;
	}
	if(r>=1e18) rlen=19,rofs=1e18;
	else while(10*rofs<=r){
		rofs*=10;
		rlen++;
	}
	cout<<solve(10,r,rlen,rofs,false,-1)-solve(10,l,llen,lofs,false,-1)<<'\n';
}