#include<bits/stdc++.h>
using namespace std;
#define int long long
long long ans(int n){
    return (n - 1)*(n + 4)*(n*n - 3*n + 4)/2;
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cout<<ans(i)<<'\n';
    return 0;
}
