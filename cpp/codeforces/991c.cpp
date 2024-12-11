#include<bits/stdc++.h>
using namespace std;
void solve(){
        string s;
        cin>>s;
        int tw=0,sx=0,sum=0;
        for(auto x:s) sum+=x-'0',tw+=x=='2',sx+=x=='3';
        if(sum%9==0) return cout<<"Yes\n",void();
        for(int i=0;i<=min(sx,6);i++){
                for(int j=0;j<=min(tw,9);j++){
                        if((sum+6*i+2*j)%9==0){
                                cout<<"Yes\n";
                                return;
                        }
                }
        }
        cout<<"No\n";
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
