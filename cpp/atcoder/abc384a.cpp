#include<bits/stdc++.h>
using namespace std;
int n;
char c1,c2;
string s;
signed main(){
    cin>>n>>c1>>c2;
    cin>>s;
    for(auto &x:s) if(x!=c1) x=c2;
    cout<<s<<'\n';
}