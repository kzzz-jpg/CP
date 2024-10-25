#include<bits/stdc++.h>
using namespace std;
int cs[3][2]={{-100,50},{-75,75},{-50,100}};
int mod;
char c;
string s;
signed main(){
    cin>>c;
    if(c=='#') mod=0;
    else if(c=='!') mod=1;
    else mod=2;
    cin>>s;
    int ans=0;
    for(auto x:s) ans+=cs[mod][x-'0'];
    cout<<ans<<'\n';
}