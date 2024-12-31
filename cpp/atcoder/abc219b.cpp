#include<bits/stdc++.h>
using namespace std;
string s[4];
string t;
signed main(){
    cin>>s[1]>>s[2]>>s[3]>>t;
    for(auto x:t) cout<<s[x-'0'];
}