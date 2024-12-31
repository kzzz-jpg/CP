#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c;
signed main(){
    cin>>a>>b>>c;
    if((a==b&&b==c)||a+b==c||a+c==b||b+c==a) cout<<"Yes\n";
    else cout<<"No\n";
}