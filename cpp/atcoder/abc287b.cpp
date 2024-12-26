#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
string s[1050],p[1050];
int n,m,ans=0;
signed main(){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>s[i],s[i]=string(s[i].begin()+3,s[i].end());
        for(int i=1;i<=m;i++) cin>>p[i],mp[p[i]]++;
        for(int i=1;i<=n;i++) if(mp[s[i]]) ans++;
        cout<<ans<<'\n';
}
