#include<bits/stdc++.h>
using namespace std;
int a,b,c;
signed main(){
    cin>>a>>b>>c;
    if((a<=b&&b<=c)||(c<=b&&b<=a)) cout<<"Yes\n";
    else cout<<"No\n";
}