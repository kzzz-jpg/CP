#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1050][1050];
int qr[150];
int n,q;
signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=1e15;
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int i=1;i<=q;i++) cin>>qr[i];
	qr[0]=0;
	qr[q+1]=n;
	for(int i=1;i<=n;i++){
		for(int l=1,r=l+i;r<=n;l++,r++){
			for(int j=1;j<=q;j++){
				int L=j==l?0:dp[l][j-1];
				int R=j==r?0:dp[l+1][r];
				dp[l][r]=min(dp[l][r],qr[j+1]-qr[j-1]+L+R);
			}
		}
	}
	cout<<dp[1][n]<<'\n';
}
