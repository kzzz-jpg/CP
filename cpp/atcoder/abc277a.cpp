#include<bits/stdc++.h>
using namespace std;
int n,k,x;
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>x,(x==k)&&(cout<<i<<'\n');
    return 0;
}