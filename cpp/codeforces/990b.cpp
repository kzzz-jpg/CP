#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<char,int> mp;
        int mx=0,mn=1e7;
        char mxc,mnc;
        for(auto x:s){
                mp[x]++;
        }
        for(auto x:mp){
                if(x.second>=mx) mx=x.second,mxc=x.first;
        }
        for(auto x:mp){
                if(x.second<mn) mn=x.second,mnc=x.first;
        }
        for(auto &x:s){
                if(x==mnc){
                        x=mxc;
                        cout<<s<<'\n';
                        return;
                }
        }

}
signed main(){
        int t;
        cin>>t;
        while(t--)solve();
}
