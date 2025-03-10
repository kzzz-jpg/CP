#include<bits/stdc++.h>
using namespace std;
int n;
string s;
signed main(){
    cin>>n>>s;
    for(int i=n/3+1;i<=n/3*2;i++) cout<<s[i-1];
    for(int i=1;i<=n/3;i++) cout<<s[i-1];
    for(int i=n/3*2+1;i<=n;i++) cout<<s[i-1];
    cout<<'\n';
}