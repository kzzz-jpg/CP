#include "bits/stdc++.h"
#include <algorithm>
#include <cassert>
using namespace std;
#define int long long
int t,d;
int sti(string x){
    int ret=0;
    for(auto y:x){
        ret=ret*10+(y-'0');
    }
    return ret;
}
string its(int x){
    string ret="";
    while(x){
        ret.push_back(x%10+'0');
        x/=10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
void solve(){
    map<int,bool> mp;
    int n;
    cin>>n;
    string pos,neg;
    while(1){
        if(mp[n]){
            cout<<n<<'\n';
            return;
        }
        mp[n]=1;
        pos=neg=its(n);
        sort(pos.begin(),pos.end(),greater<char>());
        sort(neg.begin(),neg.end());
        while(pos.size()<d) pos.push_back('0');
        n=sti(pos)-sti(neg);
        assert(n>0);
    }
}
signed main(){
    cin>>t>>d;
    while(t--) solve();
}