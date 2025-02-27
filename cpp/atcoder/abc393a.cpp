#include<bits/stdc++.h>
using namespace std;
string s,t;
signed main(){
    cin>>s>>t;
    if(s=="sick"&&s==t) cout<<1<<'\n';
    else if(s=="sick") cout<<2<<'\n';
    else if(t=="sick") cout<<3<<'\n';
    else cout<<4<<'\n';
}