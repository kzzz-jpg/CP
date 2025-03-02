#include<bits/stdc++.h>
#include <iomanip>
#include <ios>
using namespace std;
using ll = long long;
ll n,k,c,a[200500],x;
signed main(){
    cin>>n>>k>>c;
    if(c==0) return cout<<0<<'\n',0;
    cout<<n+1<<'\n';
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<0) cout<<"sub "<<i<<'\n';
        else cout<<"add "<<i<<'\n';
        x+=abs(a[i]);
    }
    long double ans=((long double)(log10(c)))/log10(x);
    cout<<"pow "<<fixed<<setprecision(18)<<' '<<ans<<'\n';
}