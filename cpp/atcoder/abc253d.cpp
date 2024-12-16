#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,b;
signed main(){
    cin>>n>>a>>b;
    int aa=((a+(n/a)*a)*(n/a)/2);
    int bb=((b+(n/b)*b)*(n/b)/2);
    int c=a*b/__gcd(a,b);
    int cc=(((c)+(n/(c))*(c))*(n/(c))/2);
    int ans=(n+1)*n/2-aa-bb+cc;
   // cerr<<aa<<' '<<bb<<' '<<cc<<'\n';
    cout<<ans<<'\n';
}