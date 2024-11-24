#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[26];
int n;
string bi[]={"","1","3","5","7","9"};
void solve(int x,int nw){
        if(x==0){
                cout<<bi[nw]<<'\n';
                return;
        }
        for(int i=5;i>=0;i--){
                if(nw>(i*dp[x])&&((i<=1)||(nw>dp[x]*i+dp[x-1]))){
                        cout<<bi[i];
                        solve(x-1,nw-i*dp[x]);
                        break;
                }
        }
}
signed main(){
        cin>>n;
        string ans;
        while(n){
                ans.push_back((n%5==0?5:n%5)+'0');
                if(n%5==0) n-=5;
                n/=5;
        }
        for(int i=ans.size()-1;i>=0;i--) cout<<bi[ans[i]-'0'];
}
