#include<bits/stdc++.h>
using namespace std;
void solve(){
        int n,m,k;
        cin>>n>>m>>k;
        string s;
        cin>>s;
        int cnt=0,ans=0;
        for(int i=0;i<s.size();i++){
                if(s[i]=='0') cnt++;
                else cnt=0;
                if(cnt>=m){
                        ans++;
                        i=i+k-1;
                        cnt=0;
                }
        }
        cout<<ans<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
