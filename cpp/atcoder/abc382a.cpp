#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
string s;
signed main(){
        cin>>n>>m;
        cin>>s;
        for(auto x:s) if(x=='.') ans++;
        cout<<ans+m<<'\n';
}
