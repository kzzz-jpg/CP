#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
map<char,int> mp;
int ans;
int dif;
signed main(){
        cin>>s;
        for(auto x:s) if(mp[x]++==0) dif++;
        if(dif<s.size()) ans++;
        for(auto x:s){
                ans+=dif-bool(mp[x]);
                if(--mp[x]==0) dif--;
        }
        cout<<ans<<'\n';
}
