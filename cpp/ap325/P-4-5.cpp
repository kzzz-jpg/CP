#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MI 1<<30
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first*b.second<b.first*a.second;
}
signed main(){
    int n;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].second;
    }
    sort(a.begin(),a.end(),cmp);
    long long ans=0;
    ll t=0;
    for(int i=0;i<n;i++){
        t+=a[i].first;
        ans+=a[i].second*t;
    }
    cout<<ans<<endl;
    return 0;
}